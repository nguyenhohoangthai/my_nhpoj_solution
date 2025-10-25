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
ll p, k, ans, f[16][136][136][2][5];
bool prime[136];
string s;
ll dp(int i, int s1, int s2, int diff, int r) {
    if (i < 0) return (prime[s1] && prime[s2] && (r == 0) && diff == 1);
    if (f[i][s1][s2][diff][r] != -1) return f[i][s1][s2][diff][r];
    ll res = 0;
    fto(n1, 0, 9) {
        fto(n2, 0, (p == 1 ? 4 : 9)) {
            int curr = 2 * n2 + n1 + r;
            int curr_num = curr % 10;
            if (p == 1 && (2*n2 + n1 >= 10)) continue;
            if ((curr_num + '0') != s[i]) continue;
            int new_r = curr / 10;
            int new_diff = diff;
            if (new_diff == 0) new_diff = (n1 != n2);
            res += dp(i-1, s1 + n1, s2 + n2, new_diff, new_r);
        }
    }
    return f[i][s1][s2][diff][r] = res;
}
signed main() {
    fastio;
    if (fopen("LTD02_03.inp", "r")) {
        freopen("LTD02_03.inp", "r", stdin);
        freopen("LTD02_03.out", "w", stdout);
    }
    fto(i, 2, 135) prime[i] = 1;
    for (int i = 2; i <= 135; ++i) {
        if (prime[i]) {
            for (int j = i * 2; j <= 135; j += i) prime[j] = 0;
        }
    }
    cin >> k >> p;
    mem(f, -1);
    s = to_string(k);
    cout << dp(sz(s) - 1, 0, 0, 0, 0) << "\n";
    return 0;
}