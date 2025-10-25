/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fat(i, a) for (auto i : a)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, k, a[100005], ans, f[100005][5][25];
vector<int> rbs;
int check(int x, int y) {
    if (x == 2 && y == 1) return 1;
    if (x == 3 && y == 2) return 1;
    if (x == 1 && y == 3) return 1;
    return 0;
}
int dp(int pos, int tt, int res) {
    if (pos > n) return 0;
    if (f[pos][tt][res] != -1) return f[pos][tt][res];
    int ret = 0;
    for (auto x : rbs) {
        int win = check(x, a[pos]);
        if (x == tt) ret = max(ret, dp(pos + 1, x, res) + win);
        else {
            if (res > 0) ret = max(ret, dp(pos + 1, x, res - 1) + win);
        }
    }
    return f[pos][tt][res] = ret;
}
int main() {
    fastio;
    cin >> n >> k;
    rbs.pb(1); rbs.pb(2); rbs.pb(3);
    fto(i, 1, n) cin >> a[i];
    memset(f, -1, sizeof f);
    fto(i, 1, 3) ans = max(ans, dp(1, i, k));
    cout << ans << "\n";
    return 0;
}