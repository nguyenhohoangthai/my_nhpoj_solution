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
int n, a[maxN], b[maxN], c[maxN];
vector<pii> proc;
long long ans;
ll solve(int l, int r, ll x) {
    if (l == r) return abs(c[l]) - x;
    int mn = oo;
    fto(i, l, r) minimize(mn, abs(c[i]));
    while (abs(c[l]) == mn) ++l;
    while (abs(c[r]) == mn) --r;
    int res = 0;
    fto(i, l, r) {
        if (l > i) continue;
        if (abs(c[i]) == mn) {
            res += solve(l, i-1, mn);
            l = i;
            while (abs(c[l]) == mn) ++l;
        }
    }
    if (l <= r) res += solve(l, r, mn);
    return res + abs(mn) - x;
}
int main() {
    fastio;
    if (fopen("P445.inp", "r")) {
        freopen("P445.inp", "r", stdin);
        freopen("P445.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n) cin >> b[i];
    fto(i, 1, n) c[i] = a[i] - b[i];
    int l = 1;
    int prv = 1;
    while (l <= n) {
        if ((1LL * c[prv]) * (1LL * c[l]) <= 0) {
            if (c[prv] != 0) proc.pb({prv, l-1});
            prv = l;
        }
        ++l;
    }
    if (c[prv] != 0) proc.pb({prv, l-1});
    for (auto x : proc) ans += solve(x.ff, x.ss, 0);
    cout << ans << "\n";
    return 0;
}