/*Code by Hoang Thai*/
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
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int m, a[305][305][305], f[305][305][305], x, y, z;
int ok(int pos) {
    return (0 <= pos && pos <= 2*m);
}
int dp(int i, int j, int k) {
    if (i == x && j == y && k == z) return f[i][j][k] = a[i][j][k];
    if (f[i][j][k] != -1) return f[i][j][k];
    int res = -oo;
    if (ok(i+1) && ok(k-1)) maximize(res, dp(i+1, j, k-1));
    if (ok(i-1) && ok(j+1)) maximize(res, dp(i-1, j+1, k));
    if (ok(j+1) && ok(k-1)) maximize(res, dp(i, j+1, k-1));
    return f[i][j][k] = res + a[i][j][k];
}
int main() {
    fastio;
    #define test "THPN25A"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> m;
    fto(i, 0, 3*m*(m+1)) {
        int q, r, s, v; cin >> q >> r >> s >> v;
        q += m; r += m; s += m;
        a[q][r][s] = v;
    }
    cin >> x >> y >> z;
    x += m; y += m; z += m;
    mem(f, -1);
    cout << dp(m, 0, m << 1) << "\n";
    return 0;
}