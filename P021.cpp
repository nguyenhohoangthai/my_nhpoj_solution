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
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int m, n, f[205][205];
pair<int, int> a[205];
int square(int x) {
    return x*x;
}
int dp(int i, int cnt) {
    if (cnt >= m && i < n) return oo;
    if (i == n && cnt < m) return oo;
    if (i == n) return 0;
    if (f[i][cnt] != -1) return f[i][cnt];
    int res = oo;
    fto(p, i+1, n) {
        if (p == i+1) res = min(res, dp(p, cnt+1));
        else res = min(res, dp(p, cnt+1) + square(a[p].ff - a[i].ss));
    }
    return f[i][cnt] = res;
}
int main() {
    fastio;
    while (cin >> n >> m) {
        if (m == 0 && n == 0) break;
        fto(i, 1, n) cin >> a[i].ff >> a[i].ss;
        mem(f, -1);
        cout << dp(1, 1) << "\n";
    }
    return 0;
}