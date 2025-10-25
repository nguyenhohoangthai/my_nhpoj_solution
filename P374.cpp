/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000009;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, k, a[1005], b[1005], f[1005][1005][15];
int dp(int i, int j, int cnt) {
    if (cnt == k) return 1;
    if (i > n || j > m) return 0;
    if (f[i][j][cnt] != -1) return f[i][j][cnt];
    int res = 0;
    if (a[i] > b[j]) res = (res + dp(i+1, j+1, cnt+1)) % oo;
    res = (res + dp(i+1, j, cnt)) % oo;
    res = (res + dp(i, j+1, cnt)) % oo;
    res = (res - dp(i+1, j+1, cnt) + oo) % oo;
    return f[i][j][cnt] = res;
}
void solve() {
    mem(f, -1);
    cout << dp(1, 1, 0) << "\n";
}

void input() {
    cin >> n >> m >> k;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, m) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
}

int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    input();
    solve();
    return 0;
}