/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define int long long
#define ss second
#define sz(a) a.size()
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
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int t, n, f[10005], gt[10005], power[10005];
int nhan(int a, int b) {
	return (a * b) % oo;
}
int lt(int a, int b) {
	if (b == 0) return 1;
	if (b & 1) return nhan(a, lt(a, b-1));
	int t = lt(a, b >> 1);
	return nhan(t, t);
}
int C(int k, int n) {
	return nhan(gt[n], lt(nhan(gt[k], gt[n-k]), oo-2));
}
void presolve() {
	gt[0] = 1;
	fto(i, 1, 10003) gt[i] = nhan(gt[i-1], i);
}
int dp(int x) {
	if (x == 0 || x == 2) return 1;
	if (x == 1) return 0;
	if (f[x]) return f[x];
	int res = lt(2, x*(x-1) / 2);
	fto(i, 1, x) res = (res - nhan(C(i, x), dp(x-i)) + oo) % oo;
	return f[x] = res;
}
signed main() {
    fastio;
    presolve();
    cin >> t;
    while (t--) {
    	cin >> n;
    	cout << dp(n) << "\n";
    }
    return 0;
}