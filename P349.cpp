/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
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
int n, h[3*maxN], dp[3*maxN];
stack<int> a, b;
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) dp[i] = oo;
    dp[1] = 0;
    fto(i, 1, n) cin >> h[i];
    a.push(1);
    b.push(1);
    fto(i, 2, n) {
    	dp[i] = dp[i-1] + 1;
    	while (!a.empty() && h[a.top()] > h[i]) {
    		dp[i] = min(dp[i], dp[a.top()] + 1);
    		a.pop();
    	}
    	if (!a.empty()) {
    		if (h[i] == h[a.top()]) {
    			dp[i] = min(dp[i], dp[a.top()] + 1);
    			a.pop();
    		}
    		else dp[i] = min(dp[i], dp[a.top()] + 1);
    	}

    	while (!b.empty() && h[b.top()] < h[i]) {
    		dp[i] = min(dp[i], dp[b.top()] + 1);
    		b.pop();
    	}
    	if (!b.empty()) {
    		if (h[i] == h[b.top()]) {
    			dp[i] = min(dp[i], dp[b.top()] + 1);
    			b.pop();
    		}
    		else dp[i] = min(dp[i], dp[b.top()] + 1);
    	}

    	a.push(i);
    	b.push(i);
    }
    cout << dp[n] << "\n";
    return 0;
}