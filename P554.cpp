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

int n, m, k, a[maxN], b[maxN], ans;
map<int, int> r;
int lt(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % k;
        a = (a * a) % k;
        b >>= 1;
    }
    return res;
}

void solve(int x, int hs) {
    fto(i, 2, sqrt(x)) {
        while (x % i == 0) {
            r[i] += hs;
            x /= i;
        }
    }
    if (x > 1) r[x] += hs;
}

signed main() {
    fastio;
    #define test "sinh"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }

    cin >> n >> m >> k;

    fto(i, 1, n) cin >> a[i];
    fto(i, 1, m) cin >> b[i];

    fto(i, 1, n) solve(a[i], 1);

    fto(i, 1, m) solve(b[i], -1);

    ans = 1;
    for (auto x : r) {
        if (x.ss == 0) continue;
        ans = (ans * lt(x.ff, x.ss)) % k;
    }

    cout << ans << "\n";

    return 0;
}