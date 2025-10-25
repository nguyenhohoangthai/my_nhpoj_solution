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
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int T, nt[maxN * 10], f[maxN], sum[maxN];
vector<int> prime;
int get_left(int x) {
    int low = 0;
    int high = sz(prime) - 1;
    int res = 0;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (prime[mid] >= x) {
            res = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return res;
}
int get_right(int x) {
    int low = 0;
    int high = sz(prime) - 1;
    int res = sz(prime) - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (prime[mid] <= x) {
            res = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return res;
}
signed main() {
    fastio;
    if (fopen("P054.inp", "r")) {
        freopen("P054.inp", "r", stdin);
        freopen("P054.out", "w", stdout);
    }
    fto(i, 2, (int) 1e6 + 5) nt[i] = 1;
    fto(i, 2, (int) 1e6 + 5) {
        if (nt[i]) {
            for (int j = i * 2; j <= (int) 1e6 + 5; j += i) nt[j] = 0;
        }
    }
    fto(i, 2, (int) 1e6 + 5) {
        if (nt[i]) prime.pb(i);
    }
    f[0] = prime[0];
    sum[0] = prime[0];
    fto(i, 1, sz(prime) - 1) {
        f[i] = (f[i-1] + (prime[i] * (i+1)) % oo) % oo;
        sum[i] = (sum[i-1] + prime[i]) % oo;
    }
    cin >> T;
    while (T--) {
        int l, r; cin >> l >> r;
        if (l > r) {
            cout << 0 << "\n";
            continue;
        }
        if (l == r && l == 1) {
            cout << 0 << "\n";
            continue;
        }
        int pos_l = get_left(l);
        int pos_r = get_right(r);
        int ans = (f[pos_r] - (pos_l - 1 >= 0 ? f[pos_l - 1] : 0) + oo) % oo;
        int new_ans = (sum[pos_r] - (pos_l - 1 >= 0 ? sum[pos_l - 1] : 0) + oo) % oo;
        new_ans = (pos_l * new_ans) % oo;
        ans = (ans - new_ans + oo) % oo;
        cout << ans << "\n";
    }
    return 0;
}