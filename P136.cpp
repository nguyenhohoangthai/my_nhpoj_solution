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
int t, n, a[105], f[105][105];
int dp(int l, int r) {
    if (l == r) return 1;
    if (f[l][r] != -1) return f[l][r];
    if (a[l] == a[r]) return f[l][r] = dp(l+1, r);
    int res = oo;
    fto(i, l, r-1) res = min(res, dp(l, i) + dp(i+1, r));
    return f[l][r] = res;
}
int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(f, -1, sizeof f);
        fto(i, 1, n) cin >> a[i];
        cout << dp(1, n) << "\n";
    }
    return 0;
}