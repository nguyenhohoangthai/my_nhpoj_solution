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
#define mem(x, a) memset(x, a, sizeof x)
#define int long long
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, a[505], f[505][5005][7];
int dp(int i, int s, int cnt) {
    if (i > n) return (s == 20 && cnt == 4);
    if (cnt > 4) return 0;
    if (f[i][s][cnt] != -1) return f[i][s][cnt];
    return f[i][s][cnt] = dp(i+1, s + a[i], cnt + 1) + dp(i+1, s, cnt);
}
signed main() {
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    mem(f, -1);
    cout << dp(1, 0, 0) << "\n";
    return 0;
}