/*Hoang Thai*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
int n, a[21][21], f[21][(1 << 20)];
int main() {
    fastio;
    #define test "P519"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        fto(j, 1, n) cin >> a[i][j];
    }
    fto(i, 1, n) {
        fto(j, 0, (1 << n) - 1) f[i][j] = oo;
    }
    f[1][1] = 0;
    fto(mask, 1, (1 << n) - 1) {
        fto(i, 1, n) {
            for (int tmp = (~mask) & ((1 << n) - 1); tmp; tmp &= (tmp - 1)) {
                int j = __builtin_ctz(tmp) + 1;
                if (BIT(mask, i-1) && !BIT(mask, j-1)) {
                    minimize(f[j][mask | MASK(j-1)], f[i][mask] + a[i][j]);
                }
            }
        }
    }
    int ans = oo;
    fto(i, 2, n) minimize(ans, f[i][(1 << n) - 1] + a[i][1]);
    cout << ans << "\n";
    return 0;
}