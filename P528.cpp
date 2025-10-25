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
string s;
int n, m;
ll f[MASK(18)][100];
ll dp(int bit, int r) {
    if (bit_count(bit) == (n + 1)) return (r == 0);
    if (f[bit][r] != -1) return f[bit][r];
    ll res = 0;
    vector<bool> used(10, 0);
    fto(i, 0, n) {
        if (bit == 0 && s[i] == '0') continue;
        if (BIT(bit, i)) continue;
        if (used[s[i] - '0']) continue;
        used[s[i] - '0'] = 1;
        res += dp(bit | MASK(i), ((r * 10) + (s[i] - '0')) % m);
    }
    return f[bit][r] = res;
}
int main() {
    fastio;
    #define test "P528"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> s >> m;
    n = sz(s) - 1;
    mem(f, -1);
    cout << dp(0, 0) << "\n";
    return 0;
}