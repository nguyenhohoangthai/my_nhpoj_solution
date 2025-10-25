/*Hoang Thai*/
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
ll a, b, n, ans, pos_x, pos_y;
string s;
pair<ll, ll> pos[maxN];
pair<ll, ll> convert(pair<ll, ll> y, char x) {
    if (x == 'U') y.ss += 1;
    if (x == 'D') y.ss -= 1;
    if (x == 'R') y.ff += 1;
    if (x == 'L') y.ff -= 1;
    return y;
}
int main() {
    fastio;
    // #define test "TS1025E"
// if (fopen(test".inp", "r")) {
//     freopen(test".inp", "r", stdin);
//     freopen(test".out", "w", stdout);
// }
    ans = 1e18;
    cin >> a >> b;
    if (a == 0 && b == 0) {
        cout << 0 << "\n";
        return 0;
    }
    cin >> s;
    n = sz(s);
    fto(i, 0, n-1) pos[i+1] = convert(pos[i], s[i]);
    fto(i, 1, n) {
        if (pos[i].ff == a && pos[i].ss == b) {
            cout << i << "\n";
            return 0;
        }
    }
    fto(i, 1, n) {
        ll k;
        if (pos[n].ff != 0) {
            k = (a - pos[i].ff) / (pos[n].ff);
            if (pos[i].ss + k * pos[n].ss != b) continue;
        }
        else if (pos[n].ss != 0) {
            k = (b - pos[i].ss) / pos[n].ss;
            if (pos[i].ff + k * pos[n].ff != a) continue;
        }
        if (pos[i].ff + k * pos[n].ff == a && pos[i].ss + k * pos[n].ss == b) {
            ans = min(ans, k*n + i);
        }
    }
    if (ans != 1e18) cout << ans << "\n";
    else cout << -1 << "\n";
    return 0;
}