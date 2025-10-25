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
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
string a, b, c, d, e, f, g, h;
double ans;
int cnt;
int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    cin >> a >> b;
    fto(i, 0, sz(a) - 1) ans += (a[i] == b[i] ? 0.25 : 0);
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    cnt = 0;
    fto(i, 0, 3) {
        if (a[i] == e[i]) ++cnt;
    }
    if (cnt == 1) ans += 0.1;
    if (cnt == 2) ans += 0.25;
    if (cnt == 3) ans += 0.5;
    if (cnt == 4) ans += 1;
    cnt = 0;
    fto(i, 0, 3) {
        if (b[i] == f[i]) ++cnt;
    }
    if (cnt == 1) ans += 0.1;
    if (cnt == 2) ans += 0.25;
    if (cnt == 3) ans += 0.5;
    if (cnt == 4) ans += 1;
    cnt = 0;
    fto(i, 0, 3) {
        if (c[i] == g[i]) ++cnt;
    }
    if (cnt == 1) ans += 0.1;
    if (cnt == 2) ans += 0.25;
    if (cnt == 3) ans += 0.5;
    if (cnt == 4) ans += 1;
    cnt = 0;
    fto(i, 0, 3) {
        if (d[i] == h[i]) ++cnt;
    }
    if (cnt == 1) ans += 0.1;
    if (cnt == 2) ans += 0.25;
    if (cnt == 3) ans += 0.5;
    if (cnt == 4) ans += 1;
    cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}