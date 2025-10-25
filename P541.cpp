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
#define int long long
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
int n, f[10001][6][6][6];
int dp(int i, int num, int c, int l) {
    if (i > n) return (c == 0 && num == l);
    if (f[i][num][c][l] != -1) return f[i][num][c][l];
    int res = (c == 0 && num == l);

    if (c > 0) res = (res + dp(i+1, num, c-1, l) * c);
    if (c < 5) res = (res + dp(i+1, num, c+1, l) * (5 - c));

    if (num < 5) res = (res + dp(i+1, num+1, c, l+1) * (5 - num)) % oo;
    if (l > 0) res = (res + dp(i+1, num, c, l-1) * l) % oo;
    if (l < num) res = (res + dp(i+1, num, c, l+1) * (num - l)) % oo;

    return f[i][num][c][l] = res;
}
signed main() {
    fastio;
    #define test "P541"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    mem(f, -1);
    cout << (dp(2, 1, 0, 1) * 5 + dp(2, 0, 1, 0) * 4) % oo << "\n";
    return 0;
}