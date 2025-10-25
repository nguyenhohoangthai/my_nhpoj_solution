/*Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
#define ff first
#define ss second
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define pii pair<int, int>
#define pq priority_queue<pii, vector<pii>, greater<pii>>
#define ll long long
#define db double
#define sz(a) (int) a.size()
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define yes "YES"
#define no "NO"
#define PI acos(-1)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 300005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int T, n, m, k;
int ans, a[maxN][5], mx_even[maxN], mx_odd[maxN], mn_even[maxN], mn_odd[maxN], f[maxN], tree[4*maxN], lazy[4*maxN];
vector<int> values;
void init(int node, int l, int r) {
    if (l == r) {
        tree[node] = f[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(node << 1, l, mid);
    init(node << 1 | 1, mid + 1, r);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}
void push(int node, int l, int r) {
    if (!lazy[node]) return;
    tree[node] += lazy[node];
    if (l != r) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int l, int r, int u, int v, int x) {
    push(node, l, r);
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        lazy[node] += x;
        push(node, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, u, v, x);
    update(node << 1 | 1, mid + 1, r, u, v, x);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}
int query(int node, int l, int r, int u, int v) {
    push(node, l, r);
    if (u > r || v < l) return 1e5;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return min(query(node << 1, l, mid, u, v), query(node << 1 | 1, mid + 1, r, u, v));
}
int main() {
    fastio;
    #define test "P389"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        mem(f, 0); mem(mn_even, 0); mem(mn_odd, 0); mem(mx_even, 0); mem(mx_odd, 0); memset(tree, 0x3f, sizeof (tree)); mem(lazy, 0); values.clear();
        fto(i, 1, m) {
            mn_even[i] = mn_odd[i] = oo;
            fto(j, 1, k) {
                cin >> a[i][j];
                if (a[i][j] & 1) {
                    maximize(mx_odd[i], a[i][j]);
                    minimize(mn_odd[i], a[i][j]);
                }
                else {
                    maximize(mx_even[i], a[i][j]);
                    minimize(mn_even[i], a[i][j]);
                }
            }
        }

        f[0] = n;
        fto(i, 1, m) {
            if (mx_even[i] && mx_odd[i]) f[i] = f[i-1] - min(mx_even[i], mx_odd[i]);
            else if (mx_even[i] == 0) f[i] = f[i-1] + mn_odd[i];
            else if (mx_odd[i] == 0) f[i] = f[i-1] + mn_even[i];
            if (f[i] <= 0) break;
        }
        if (f[m] <= 0) cout << -1 << "\n";
        else {
            init(1, 1, m);

            fto(i, 1, m) {
                if (mx_even[i] && mx_odd[i]) {
                    if (min(mx_even[i], mx_odd[i]) == mx_odd[i]) values.pb(0);
                    else {
                        if (query(1, 1, m, i, m) + mx_even[i] - mx_odd[i] > 0) {
                            values.pb(0);
                            update(1, 1, m, i, m, mx_even[i] - mx_odd[i]);
                        }
                        else values.pb(1);
                    }
                }
                else if (mx_even[i] == 0) {
                    if (query(1, 1, m, i, m) - mn_odd[i] - mx_odd[i] > 0) {
                        values.pb(0);
                        update(1, 1, m, i, m, -mn_odd[i] - mx_odd[i]);
                    }
                    else values.pb(1);
                }
                else if (mx_odd[i] == 0) values.pb(0);
            }
            fto(i, 0, sz(values) - 2) cout << values[i] << " ";
            cout << values.back() << "\n";
        }
    }
    return 0;
}