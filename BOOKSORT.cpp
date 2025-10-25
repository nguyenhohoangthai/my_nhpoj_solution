/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
#define ff first
#define ss second
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define pii pair<int, int>
#define pq priority_queue<pii, vector<pii>, greater<pii>>
#define ll long long
#define db double
#define sz(a) (int) a.size()
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define yes "YES"
#define no "NO"
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, a[maxN], dp[maxN], cnt[maxN], _first[maxN], _last[maxN];
int main() {
    fastio;
    if (fopen("P011.inp", "r")) {
        freopen("P011.inp", "r", stdin);
        freopen("P011.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i];
        if (!_first[a[i]]) _first[a[i]] = i;
        _last[a[i]] = i;
    }
    dp[n] = 1;
    cnt[a[n]] = 1;
    fdto(i, n-1, 1) {
        dp[i] = dp[i+1];
        ++cnt[a[i]];
        if (i == _first[a[i]]) maximize(dp[i], dp[_last[a[i]] + 1] + cnt[a[i]]);
        else maximize(dp[i], cnt[a[i]]);
    }
    cout << n - dp[1] << "\n";
    return 0;
}