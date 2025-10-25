/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define sz(a) a.size()
#define int long long
#define cell(a, i, j) a.cell[i][j]
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
int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int t, n, mx, mn;
int nhan(int a, int b) {
    return 1LL * (a * b) % oo;
}
// ll nhan(ll a, ll b){
//     ll m = oo;
//     ll ret = a*b - m*(long long)(1.L/m*a*b);
//     return ret + m*(ret < 0) - m*(ret >= (long long)(m));
// }
int luythua(int a, int b) {
    if (b == 0) return 1LL;
    if (b & 1) return nhan(a, luythua(a, b-1));
    int t = luythua(a, b/2);
    return nhan(t, t);
}
signed main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        mx = nhan(nhan(nhan(n, 2*(n-1)+1), n-1), luythua(6, oo-2));
        if (n & 1) mn = nhan(luythua(n/2, 2), n);
        else mn = (nhan(luythua(n/2, 2), n/2) + nhan(luythua(n/2-1, 2), n/2)) % oo;
        cout << mn << " " << mx << "\n";
    }
    return 0;
}