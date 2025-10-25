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
const int maxN = 1000005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int c[maxN], sum, fact[maxN], inv[maxN];
int lt(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % oo;
        a = (a * a) % oo;
        b >>= 1;
    }
    return res;
}

int nhan(int x, int y) {
    return (x * y) % oo;
}

void init() {
    fact[0] = 1;
    fto(i, 1, maxN-5) fact[i] = nhan(fact[i-1], i);
    inv[maxN-5] = lt(fact[maxN-5], oo-2);
    fdto(i, maxN-5-1, 0) inv[i] = nhan(inv[i+1], (i + 1));
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return nhan(fact[n], nhan(inv[k], inv[n-k]));
}


int divide(int x, int y) {
    return C(x+y-1, y-1);
}

signed main() {
    fastio;
    #define test "P555"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    fto(i, 1, 9) cin >> c[i];

    sum = c[1];

    init();
    int ans = 1;

    fto(i, 2, 9) {
        if (c[i] == 0) continue;
        ans = nhan(ans, divide(sum, c[i]));
        sum += c[i];
    }
    cout << ans << "\n";
    return 0;
}