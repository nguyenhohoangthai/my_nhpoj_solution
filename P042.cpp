/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3", "unroll-loops")
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
using namespace __gnu_pbds;
const int base = 311;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, a[maxN], b[maxN], cnt[maxN];

set<int> st, value;
gp_hash_table<int, int> color, pos;

int lt(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return (lt(a, b-1) * a) % oo;
    int t = lt(a, b >> 1);
    return (t * t) % oo;
}

signed main() {
    fastio;
    #define test "P042"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i], st.insert(a[i]);
    cin >> m;
    fto(i, 1, m) cin >> b[i], st.insert(b[i]);

    int num = 0;
    for (auto x : st) color[x] = num++;

    fto(i, 1, n) a[i] = color[a[i]];
    fto(i, 1, m) b[i] = color[b[i]];

    fdto(k, min(n, m), 1) {
        value.clear();
        pos.clear();
        int sum = 0;
        fto(i, 1, k) sum += lt(base, a[i]);

        int l = 1;
        int r = k;
        while (r <= n) {
            if (r > n) break;

            value.insert(sum);
            pos[sum] = l;

            sum -= lt(base, a[l]);
            ++l;
            ++r;
            sum += lt(base, a[r]);
        }

        fto(i, 1, n) cnt[a[i]] = 0;

        sum = 0;
        fto(i, 1, k) sum += lt(base, b[i]);

        l = 1;
        r = k;
        while (r <= m) {
            if (r > m) break;

            if (value.find(sum) != value.end()) {
                cout << k << " " << pos[sum] << " " << l << "\n";
                return 0;
            }

            sum -= lt(base, b[l]);
            ++l;
            ++r;
            sum += lt(base, b[r]);
        }
    }

    cout << "0 -1 -1\n";
    return 0;
}