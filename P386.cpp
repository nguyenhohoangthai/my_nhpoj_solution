/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
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
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, tree[maxN * 8];
pii a[maxN];
vector<int> t, color;
void update(int node, int l, int r, int u, int v) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) tree[node] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(node*2, l, mid, u, v);
    update(node*2+1, mid+1, r, u, v);
    tree[node] = max(tree[node*2], tree[node*2+1]);
    return;
}
int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return -oo;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return max(query(node*2, l, mid, u, v), query(node*2+1, mid+1, r, u, v));
}
int change(int x) {
    int low = 0;
    int high = sz(t) - 1;
    int p = sz(t);
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (t[mid] > x) {
            p = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    --p;
    return color[p];
}
int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i].ff >> a[i].ss;
        ++a[i].ff; ++a[i].ss;
        t.pb(a[i].ff);
        t.pb(a[i].ss);
    }
    sort(a+1, a+n+1);
    sort(t.begin(), t.end());
    color.resize(sz(t));
    color[0] = 1;
    fto(i, 1, sz(t) - 1) {
        if (t[i] == t[i-1]) color[i] = color[i-1];
        else color[i] = color[i-1] + 1;
    }

    fto(i, 1, n) {
        a[i].ff = change(a[i].ff);
        a[i].ss = change(a[i].ss);
    }

    fto(i, 1, n) {
        update(1, 1, 2*n, a[i].ss, query(1, 1, 2*n, 1, a[i].ff) + 1);
    }
    cout << tree[1] << "\n";
    return 0;
}