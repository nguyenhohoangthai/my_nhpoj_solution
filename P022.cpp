/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define int long long
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
int t, k, h, dpB[maxN], dpC[maxN], sum, ans;
multiset<int> value;
struct present {
int a, b, c;
};
int cmp(present x, present y) {
	return (x.b - x.c) > (y.b - y.c);
}
signed main() {
    fastio;
    cin >> t >> k >> h;
    present qua[t+k+h+5];
    fto(i, 1, t+k+h) cin >> qua[i].a >> qua[i].b >> qua[i].c;
    sort(qua+1, qua+t+k+h+1, cmp);
    fto(i, 1, t+k+h) {
    	value.insert(qua[i].b - qua[i].a);
    	sum += qua[i].b - qua[i].a;
    	if (sz(value) > k) {
    		sum -= *value.begin();
    		value.erase(value.begin());
    	}
    	dpB[i] = sum;
    }
    sum = 0;
    value.clear();
    fdto(i, t+k+h, 1) {
    	value.insert(qua[i].c - qua[i].a);
    	sum += qua[i].c - qua[i].a;
    	if (sz(value) > h) {
    		sum -= *value.begin();
    		value.erase(value.begin());
    	}
    	dpC[i] = sum;
    }
    ans = -oo;
    fto(i, k, t+k) {
    	ans = max(ans, dpB[i] + dpC[i+1]);
    }
    fto(i, 1, t+k+h) ans += qua[i].a;
    cout << ans << "\n";
    return 0;
}