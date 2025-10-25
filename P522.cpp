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
#define PI acos(-1)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, w, v, f[51][201][201];
pii a[51];
int dp(int i, int rw, int rv) {
    if (rw > w || rv > v) return -oo;
    if (i > n) return 0;
    if (f[i][rw][rv] != -1) return f[i][rw][rv];
    int res = dp(i+1, rw, rv);
    if (rw + a[i].ff <= w && rv + a[i].ss <= v) maximize(res, dp(i+1, rw + a[i].ff, rv + a[i].ss) + a[i].ff);
    return f[i][rw][rv] = res;
}

int main() {
    fastio;
    #define test "P522"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> w >> v;
    fto(i, 1, n) cin >> a[i].ff >> a[i].ss;
    mem(f, -1);
    cout << dp(1, 0, 0) << "\n";
    return 0;
}