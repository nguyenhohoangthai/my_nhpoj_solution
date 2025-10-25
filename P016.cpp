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
int t;
ll k;
pair<ll, ll> ans;
int main() {
    fastio;
    #define test "P016"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> t;
    while (t--) {
        cin >> k;
        if (k <= 2) {
            cout << -1 << " " << -1 << "\n";
            continue;
        }
        ans = make_pair(-1, -1);
        for (ll n = 1; n <= 1LL * sqrt(k*2); ++n) {
            ll m = (2 * k - n - 1) / (2 * n + 1);
            if (n * m + (n + 1) * (m + 1) == 2 * k) {
                if (ans.ff == -1 && ans.ss == -1) ans = make_pair(n, m);
                else if (abs(ans.ff - ans.ss) > abs(n - m)) ans = make_pair(n, m);
            }
        }
        cout << ans.ff << " " << ans.ss << "\n";
    }
    return 0;
}