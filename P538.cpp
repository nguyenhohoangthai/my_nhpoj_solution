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
const double eps = 1e-9;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct pos {
int x, y, r;
    pos() : x(0), y(0), r(0) {}
    pos(int x, int y, int r) : x(x), y(y), r(r) {}
};
int T, n, cross[20][20], ans;
vector<pos> a;
int square(int x) {
    return x * x;
}
int dist(int i, int j) {
    return square(a[i].x - a[j].x) + square(a[i].y - a[j].y);
}
void solve() {
    ans = 0;
    mem(cross, 0);
    fto(i, 0, n-1) {
        fto(j, 0, n-1) cross[i][j] = (dist(i, j) > square(a[i].r + a[j].r));
    }
    fto(mask, 1, MASK(n) - 1) {
        int sum = 0;
        vector<int> process;
        for (int sub = mask; sub; sub &= (sub - 1)) {
            int i = __builtin_ctz(sub);
            sum += square(a[i].r);
            process.pb(i);
        }
        fto(i, 0, sz(process) - 2) {
            if (!sum) break;
            fto(j, i+1, sz(process) -1) {
                if (!cross[process[i]][process[j]]) {
                    sum = 0;
                    break;
                }
            }
        }
        maximize(ans, sum);
    }
    cout << ans << "\n";
}

int main() {
    fastio;
    #define test "P538"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n;
        a.clear();
        a.resize(n);
        fto(i, 0, n-1) cin >> a[i].x >> a[i].y >> a[i].r;
        solve();
    }
    return 0;
}