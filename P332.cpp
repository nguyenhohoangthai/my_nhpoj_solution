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
int check(int x) {
	if (x == 2 || x == 3) return 1;
	if (x == 1 || x % 2 == 0 || x % 3 == 0) return 0;
	for (int i = 5; i <= sqrt(x); i += 6) {
		if (x % i == 0 || (x % (i + 2) == 0)) return 0;
	}
	return 1;
}
int n, a[10005], ans;
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n-1) {
    	fto(j, i+1, n) {
    		if (check(a[i] + a[j])) ++ans;
    	}
    }
    cout << ans << "\n";
    return 0;
}