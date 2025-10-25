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
int n, l, r, ans;
vector<int> num = {2, 3, 5, 7};
bool mulmod(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

long long powmod(long long a, long long d, long long mod) {
    long long res = 1;
    while (d) {
        if (d & 1) res = (long long)((__int128)res * a % mod);
        a = (long long)((__int128)a * a % mod);
        d >>= 1;
    }
    return res;
}

bool millerTest(long long d, long long n, long long a) {
    long long x = powmod(a, d, n);
    if (x == 1 || x == n - 1) return true;
    while (d != n - 1) {
        x = (long long)((__int128)x * x % n);
        d <<= 1;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrimeMR(long long n) {
    if (n < 2) return false;
    static long long smallPrimes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (long long p : smallPrimes) {
        if (n == p) return true;
        if (n % p == 0 && n != p) return false;
    }
    long long d = n - 1;
    while ((d & 1) == 0) d >>= 1;
    long long bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (long long a : bases) {
        if (a % n == 0) continue;
        if (!millerTest(d, n, a)) return false;
    }
    return true;
}

bool check(ll x) {
    return isPrimeMR(x);
}
void sinh(ll x) {
    if (x > r) return;
    if (l <= x && x <= r) ans += check(x);
    fto(i, 0, 3) sinh(x * 10 + num[i]);
}
int main() {
    fastio;
    #define test "P465"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> l >> r;
    sinh(0LL);
    cout << ans << "\n";
    return 0;
}