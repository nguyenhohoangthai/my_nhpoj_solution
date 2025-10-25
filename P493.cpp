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
int n, a[21], ans;
int add(ll x, ll y) {
    ll res = 0;
    ll d = 1;
    while (x && y) {
        ll m_x = x % 10;
        ll m_y = y % 10;
        x /= 10; y /= 10;
        if (m_x + m_y >= 10) return 0;
        res += (m_x + m_y) * d;
        d *= 10;
    }
    return 1;
}
int main() {
    fastio;
    #define test "P493"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    fto(i, 0, MASK(n) - 1) {
        ll res = 0;
        bool flag = true;
        fto(j, 0, n-1) {
            if (BIT(i, j)) {
                if (add(res, 1LL * a[j+1])) {
                    res += 1LL * a[j+1];
                    continue;
                }
                flag = false;
                break;
            }
        }
        if (flag) maximize(ans, bit_count(i));
    }
    cout << ans << "\n";
    return 0;
}