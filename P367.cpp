/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bitset<1500> a[1500];
int n, m, ans, link[1505][1505];
int main() {
    fastio;
    cin >> n >> m;
    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        link[u][v] = link[v][u] = 1;
        if (u < v) a[u][v] = 1;
        if (v < u) a[v][u] = 1;
    }
    // fto(i, 1, n) cout << i << " " << a[i].count() << "\n";
    fto(i, 1, n) {
        fto(j, i+1, n) {
            if (!link[i][j]) continue;
            bitset<1500> c = (a[i] & a[j]);
            ans += c.count();
        }
    }
    cout << ans << "\n";
    return 0;
}