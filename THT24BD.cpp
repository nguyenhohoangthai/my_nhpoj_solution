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
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
long long n, m, k, a[1005], f[1005][1005], prefix[1005];
long long dp(int p, long long res) {
    if (p > n && res == 0) return 0LL;
    if (p > n) return -10000000000007;
    if (f[p][res]) return f[p][res];
    long long ret = dp(p+1, res);
    ret = max(ret, dp(p+m, res - 1) + prefix[p+m-1] - prefix[p-1]);
    return f[p][res] = ret;
}
int main() {
    fastio;
    cin >> n >> m >> k;
    fto(i, 1, n) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    cout << dp(1, k) << "\n";
    return 0;
}