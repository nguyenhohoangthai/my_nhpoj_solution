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
const int maxN = 1000005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User
bool maximize(ll &a, ll b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n;
ll a[maxN], sum, f[maxN], ans;
struct line {
    ll a, b;
    line(ll _a, ll _b) {
        a = _a;
        b = _b;
    }
    line() {
        a = 0;
        b = -1e18;
    }
    long long get(long long x) {
        return a * x + b;
    }
};
line tree[2][4*maxN];
void update(line a, int node, int l, int r, int type) {
    if (l == r) {
        if (a.get(l) > tree[type][node].get(l)) tree[type][node] = a;
        return;
    }
    int mid = (l+r) >> 1;
    if (tree[type][node].a < a.a) swap(tree[type][node], a);
    if (tree[type][node].get(mid) < a.get(mid)) {
        swap(tree[type][node], a);
        update(a, node << 1 | 1, mid+1, r, type);
    }
    else update(a, node << 1, l, mid, type);
}
long long query(int node, int l, int r, long long x, int type) {
    if (l == r) return tree[type][node].get(x);
    int mid = (l + r) >> 1;
    ll cur = tree[type][node].get(x);
    if (x <= mid) return max(cur, query(node << 1, l, mid, x, type));
    return max(cur, query(node << 1 | 1, mid + 1, r, x, type));
}
int main() {
    fastio;
    if (fopen("P031.inp", "r")) {
        freopen("P031.inp", "r", stdin);
        freopen("P031.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i];
        sum += a[i] * i;
        f[i] = f[i-1] + a[i];
    }
    ans = sum;
    fto(i, 1, n) {
        update(line(i, -f[i]), 1, 1, maxN, 0);
        update(line(i, -f[i-1]), 1, 1, maxN, 1);
    }
    fto(i, 1, n) {
        maximize(ans, sum - a[i] * i + f[i] + query(1, 1, maxN, a[i], 0));
        maximize(ans, sum - a[i] * i + f[i-1] + query(1, 1, maxN, a[i], 1));
    }
    cout << ans << "\n";
    return 0;
}