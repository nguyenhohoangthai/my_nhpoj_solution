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
#define int long long
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
const int maxN = 1000005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n;
ll ans, a[maxN];
vector<int> values;
map<int, int> cnt;
int get(ll x) {
    int res = 0;
    while (x) {
        res |= MASK(x % 10);
        x /= 10;
    }
    return res;
}
signed main() {
    fastio;
    #define test "sinh"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i];
        int tmp = get(a[i]);
        values.pb(tmp);
        ++cnt[tmp];
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    fto(i, 0, sz(values) - 2) {
        fto(j, i+1, sz(values) - 1) {
            if (values[i] & values[j]) {
                ans += cnt[values[i]] * cnt[values[j]];
            }
        }
    }
    for (auto x : values) ans += (cnt[x] * (cnt[x]-1) >> 1);
    cout << ans << "\n";
    return 0;
}