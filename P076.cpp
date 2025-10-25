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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
long long n, f[10005][1005];
pair<long long, long long> a[10005];
long long dp(long long i, long long s) {
	if (i > n) return 0LL;
    if (f[i][s]) return f[i][s];
	long long res = dp(i+1, s);
	if (s <= a[i].ff) res = max(res, dp(i+1, s+1) + a[i].ss);
	return f[i][s] = res;
}
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i].ss >> a[i].ff;
    sort(a+1, a+n+1);
    // fto(i, 1, n) cout << a[i].ff << " " << a[i].ss << "\n";
cout << dp(1, 0);
    return 0;
}