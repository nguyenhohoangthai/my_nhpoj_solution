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
const int maxN = 105;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};

int p, q, r, a[maxN], b[maxN], c[maxN], ans;
int f[maxN][maxN][maxN];
int dp(int i, int j, int k) {
    if (f[i][j][k] != -1) return f[i][j][k];
    int res = 0;
    if (i > 0 && j > 0) maximize(res, dp(i-1, j-1, k) + a[i] * b[j]);
    if (i > 0 && k > 0) maximize(res, dp(i-1, j, k-1) + a[i] * c[k]);
    if (j > 0 && k > 0) maximize(res, dp(i, j-1, k-1) + b[j] * c[k]);
    return f[i][j][k] = res;
}
int main() {
    fastio;
    #define test "sinh"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }

    cin >> p >> q >> r;
    fto(i, 1, p) cin >> a[i];
    fto(i, 1, q) cin >> b[i];
    fto(i, 1, r) cin >> c[i];

    sort(a+1, a+p+1);
    sort(b+1, b+q+1);
    sort(c+1, c+r+1);

    mem(f, -1);
    cout << dp(p, q, r) << "\n";
    return 0;
}