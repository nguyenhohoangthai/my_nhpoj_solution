/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
#define ff first
#define ss second
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#pragma GCC optimize("O3", "unroll-loops")
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
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, b[maxN], place[31], cnt, f[31][1025];
vector<pii> a;
vector<int> unt[31];

int ok(int x) {
    int d = 2;
    int r = x;
    while (x > 1) {
        bool ok = false;
        while (x % d == 0) {
            if (ok) return 0;
            unt[r].pb(d);
            x /= d;
            ok = true;
        }
        ++d;
    }
    return 1;
}
int lt(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return (a * lt(a, b-1)) % oo;
    int t = lt(a, b/2);
    return (t * t) % oo;
}
int dp(int i, int bit) {
    if (i == sz(a)) return 1;
    if (f[i][bit] != -1) return f[i][bit];

    int res = dp(i+1, bit);
    bool check = true;
    for (auto x : unt[a[i].ff]) {
        if (BIT(bit, place[x]) == 1) {
            check = false;
            break;
        }
    }
    int bit_t = bit;
    if (check == true) {
        for (auto x : unt[a[i].ff]) bit_t |= MASK(place[x]);
        if (a[i].ff > 1) res = (res + a[i].ss * dp(i+1, bit_t)) % oo;
        else res = (res + (lt(2, a[i].ss) - 1) * dp(i+1, bit_t)) % oo;
    }
    return f[i][bit] = res;
}

signed main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    place[2] = 0; place[3] = 1; place[5] = 2; place[7] = 3; place[11] = 4; place[13] = 5; place[17] = 6; place[19] = 7; place[23] = 8; place[29] = 9;

    cin >> n;
    fto(i, 1, n) cin >> b[i];
    sort(b+1, b+n+1);
    int cnt = 1;
    fto(i, 2, n + 1) {
        if (b[i] != b[i-1]) {
            if (ok(b[i-1])) a.pb({b[i-1], cnt});
            cnt = 1;
        }
        else ++cnt;
    }
    mem(f, -1);
    cout << dp(0, 0) - 1 << "\n";
    return 0;
}