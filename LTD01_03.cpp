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
long long t, n, ans;
pair<long long, long long> top[3*maxN], last[3*maxN];
long long f_top(long long low, long long high, long long cmp) {
	long long res = n+1;
	while (low <= high) {
		long long mid = (low + high) >> 1;
		if (top[mid].ff >= cmp) {
			high = mid - 1;
			res = mid;
		} else low = mid + 1;
	}
	return (n - res + 1);
}
long long f_last(long long low, long long high, long long cmp) {
	long long res = 0;
	while (low <= high) {
		long long mid = (low + high) >> 1;
		if (last[mid].ff <= cmp) {
			low + mid + 1;
			res = mid;
		} else high = mid - 1;
	}
	return res;
}
long long solve() {
	cin >> n;
	fto(i, 1, n) {
		cin >> top[i].ff >> top[i].ss;
		last[i].ff = top[i].ss;
		last[i].ss = top[i].ff;
	}
	sort(top+1, top+n+1);
	sort(last+1, last+n+1);
    ans = (n-1) * n / 2;
    fto(i, 1, n) {
    	ans -= f_top(i+1, n, top[i].ss);
    	ans -= f_last(i+1, n, last[i].ss);
    }
    return ans;
}
int main() {
    fastio;
    cin >> t;
    while (t--) {
    	cout << solve() << "\n";
    }
    return 0;
}