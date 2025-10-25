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
#define int ll
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
ll n, k, a[maxN], ans;
int check(ll x) {
    ll sum = 0;
    ll cnt = 0;
    fto(i, 1, n) {
        if (a[i] > x) return 0;
        if (sum + a[i] > x) {
            sum = a[i];
            ++cnt;
        } else sum += a[i];
    }
    return (cnt < k);
}
signed main() {
    fastio;
    if (fopen("NY25_C.inp", "r")) {
        freopen("NY25_C.inp", "r", stdin);
        freopen("NY25_C.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i];
    ll low = 0;
    ll high = (ll) 1e18;
    while (low <= high) {
        ll mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}