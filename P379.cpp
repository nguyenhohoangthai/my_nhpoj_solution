/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, a[maxN], f[maxN][2];
int dp(int i, int t) {
    if (i > n) return 0;
    if (f[i][t] != -1) return f[i][t];
    int res = dp(i+1, 0);
    if (t == 0) maximize(res, dp(i+1, 1) + a[i]);
    return f[i][t] = res;
}
int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    mem(f, -1);
    cout << dp(1, 0) << "\n";
    return 0;
}