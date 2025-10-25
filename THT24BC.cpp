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
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
long long k, n, s, t, e, m, low, high, mid, ans;
long long check(long long x) {
    long long dismiss = 0;
    if (s * x > k) dismiss += s * x - k;
    if (t * x > k) dismiss += t * x - k;
    if (e * x > k) dismiss += e * x - k;
    if (m * x > k) dismiss += m * x - k;
    if (dismiss <= n) return 1LL;
    return 0LL;
}
int main() {
    fastio;
    cin >> k >> n >> s >> t >> e >> m;
    low = 0;
    high = 10000000000000;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}