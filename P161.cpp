#include <bits/stdc++.h>
#define oo 1000000007
#define pb push_back
#define ff first
#define ss second
#define fto(i, a, b) for (long long i = a; i <= b; ++i)
using namespace std;
long long n, ans, f[100005];

long long dp(long long x){
	if (x == 1) return 1;
	if (f[x] > 0) return f[x];
	long long res = 0;
	fto(i, 1, x-1){
		res = (res + dp(i) * dp(x-i)) % oo;
	}
	return f[x] = res;
}

void solve(){
	cout << dp(n+1) % oo;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    solve();
}