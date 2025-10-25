/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define int long long
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
int n, k, a[maxN], pref[maxN];
signed main() {
    fastio;
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n) pref[i] = pref[i-1] + i;
    int low = 1;
    int high = n;
    int p = n;
    while (low <= high) {
    	int mid = (low + high) >> 1;
    	if (pref[mid] >= k) {
    		p = mid;
    		high = mid - 1;
    	} else low = mid + 1;
    }
    cout << a[p - pref[p] + k] << "\n";
    return 0;
}