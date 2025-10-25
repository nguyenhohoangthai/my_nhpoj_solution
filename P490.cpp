/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
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
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, x;
int get(int x) {
    int res = 0;
    for (int i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            res += i;
            if (x / i == i) break;
            res += x / i;
        }
    }
    return (res == (x << 1));
}
signed main() {
    fastio;
    if (fopen("P490.inp", "r")) {
        freopen("P490.inp", "r", stdin);
        freopen("P490.out", "w", stdout);
    }
    int ans = 0;
    cin >> n;
    fto(i, 1, n) {
        cin >> x;
        ans += get(x);
    }
    cout << ans << "\n";
    return 0;
}