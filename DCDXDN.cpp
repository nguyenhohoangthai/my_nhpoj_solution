#include <bits/stdc++.h>
#define oo 1000000007
#define pb push_back
#define ff first
#define ss second
#define fto(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
int n, a[1005], f[1005][1005];

int dp(int x, int y){
	int res = 0;
	if (x == y) return 1;
	if (x > y) return 0;
	if (f[x][y] != 0) return f[x][y];
	if (a[x] == a[y]) res = max(res, dp(x+1, y-1) + 2);
	res = max(res, dp(x+1, y));
	res = max(res, dp(x, y-1));
	return f[x][y] = res;
}

void solve(){
	cout << dp(1, n);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    solve();
}