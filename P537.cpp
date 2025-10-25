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
int T, n, ans, cnt;
vector<pair<double, double>> coor;
// nam mô a di đà phật
// nam mô a di đà phật
// nam mô a di đà phật
void solve() {
    ans = 1;
    fto(i, 0, n-1) {
        fto(j, 0, n-1) {
            if (i == j) continue;
            double coor_x = coor[j].ff - coor[i].ff;
            double coor_y = coor[j].ss - coor[i].ss;
            int res = 2;
            fto(k, 0, n-1) {
                if (k == i || k == j) continue;
                double coor_x_new = coor[k].ff - coor[j].ff;
                double coor_y_new = coor[k].ss - coor[j].ss;
                if (fabs(coor_x * coor_y_new - coor_x_new * coor_y) < eps) ++res;
            }
            maximize(ans, res);
        }
    }
    cout << ans << "\n";
}
int main() {
    fastio;
    #define test "P537"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n;
        coor.clear();
        coor.resize(n);
        fto(i, 0, n-1) cin >> coor[i].ff >> coor[i].ss;

        sort(coor.begin(), coor.end(), [] (pair<double, double> x, pair<double, double> y) {if (x.ff == y.ff) return x.ss < y.ss; return x.ff < y.ff;});
        coor.erase(unique(coor.begin(), coor.end()), coor.end());
        n = sz(coor);

        solve();
    }
    return 0;
}