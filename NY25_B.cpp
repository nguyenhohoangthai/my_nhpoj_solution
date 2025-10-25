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
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
ll n, a[maxN];
ll sum, prod, ans;
int main() {
    fastio;
    if (fopen("NY25_B.inp", "r")) {
        freopen("NY25_B.inp", "r", stdin);
        freopen("NY25_B.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i];
        sum += a[i];
        prod += a[i] * a[i];
    }
    ans = (ll) 1e18;
    for (ll i = 1; i <= (ll) n; ++i) ans = min(ans, n * i * i - 2 * i * sum + prod);
    cout << ans << "\n";
    return 0;
}