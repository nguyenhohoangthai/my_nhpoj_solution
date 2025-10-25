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
int T, n, a[maxN];
ll dp[5001][5001][2], sum[5001];
int main() {
    fastio;
    #define test "NCK006"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n;
        fto(i, 1, n) cin >> a[i], sum[i] = sum[i-1] + a[i];
        fto(l, 1, n) {
            fto(r, l, n) dp[l][r][0] = dp[l][r][1] = -1e14;
            if (n & 1) dp[l][l][0] = a[l];
            else dp[l][l][1] = a[l];
        }

        fto(len, 2, n) {
            fto(l, 1, n-len+1) {
                int r = l + len - 1;
                ll add = sum[r] - sum[l-1];
                dp[l][r][0] = max(add - dp[l+1][r][1], add - dp[l][r-1][1]);
                dp[l][r][1] = max(add - dp[l+1][r][0], add - dp[l][r-1][0]);
            }
        }

        // fto(l, 1, n) {
//     fto(r, l, n) cout << l << " " << r << " " << dp[l][r][0] << " " << dp[l][r][1] << "\n";
// }
cout << dp[1][n][0] << "\n";

    }
    return 0;
}