/*Hoang Thai*/
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
#pragma GCC optimize("O3", "unroll-loops")
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
int T, n;
int a, b, f[10][2][2];
string x, y;
int dp(int i, int tx, int ty) {
    if (i == n) return 0;
    if (f[i][tx][ty] != -1) return f[i][tx][ty];
    int res = oo;

    int start, end;
    if (tx == 0) start = 0;
    else start = (x[i] - '0');

    if (ty == 0) end = 9;
    else end = (y[i] - '0');

    fto(d, start, end) {
        int add = 0;
        if (d == (x[i] - '0')) ++add;
        if (d == (y[i] - '0')) ++add;
        minimize(res, dp(i + 1, (d == start && tx), (d == end && ty)) + add);
    }
    return f[i][tx][ty] = res;
}

void solve() {
    mem(f, -1);
    x = to_string(a);
    y = to_string(b);
    n = sz(x);
    cout << dp(0, 1, 1) << "\n";
}
int main() {
    fastio;
    #define test "NCK004"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> a >> b;
        solve();
    }
    return 0;
}