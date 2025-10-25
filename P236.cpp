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
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
string a, b;
int n, m, dp[5005][5005], best[5005], ans;
vector<int> vt[26];
int main() {
    fastio;
    #define test "P236"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> a >> b;
    if (sz(a) < sz(b)) swap(a, b);

    n = sz(a) - 1;
    m = sz(b) - 1;

    fto(i, 0, n) vt[a[i] - 'A'].pb(i);
    mem(best, 0x3f);
    mem(dp, -1);

    best[0] = -1;

    fto(i, 0, m) {
        int ch = b[i] - 'A';
        fto(j, 1, m+1) {
            if (i + 1 < j) continue;
            int mx = best[j-1];

            int low = 0;
            int high = sz(vt[ch]) - 1;
            int res = -1;

            while (low <= high) {
                int mid = (low + high) >> 1;
                if (vt[ch][mid] > mx) {
                    res = vt[ch][mid];
                    high = mid - 1;
                }
                else low = mid + 1;
            }

            if (res == -1) continue;
            dp[i][j] = res;
        }
        fto(j, 1, m+1) {
            if (dp[i][j] == -1) continue;
            minimize(best[j], dp[i][j]);
            maximize(ans, j);
        }
    }

    cout << ans << "\n";
    return 0;
}