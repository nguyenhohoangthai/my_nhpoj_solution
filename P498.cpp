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
int n, k, a[maxN];
ll ans;
int check(ll x) {
    ll res = 0;
    fto(i, 1, n) res += x / a[i];
    return (res >= k);
}
int main() {
    fastio;
    if (fopen("P498.inp", "r")) {
        freopen("P498.inp", "r", stdin);
        freopen("P498.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n) {
        cin >> a[i];
        if (a[i] == 0) {
            cout << 0 << "\n";
            return 0;
        }
    }
    ll low = 0;
    ll high = k * a[1];
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