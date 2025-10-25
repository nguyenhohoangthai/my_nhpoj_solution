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
const double eps = 1e-10;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(ll &a, ll b) {return (a > b ? (a = b) : 0);};
struct point {
    db x, y, d, v;
    point() : x(0), y(0), d(0), v(0) {}
    point(db x, db y, db d, db v) : x(x), y(y), d(d), v(v) {}
};

int T, n;
ll ans;
db r;
point a[1005];
ll make_round(db x) {
    return nearbyint(x);
}
ll solve(int i, int j) {
    db x_1 = a[i].x;
    db y_1 = a[i].y;

    db x_2 = a[j].x;
    db y_2 = a[j].y;

    if (x_1 == x_2 && y_1 == y_2) return 1e18;

    db v_1 = a[i].v;
    db v_2 = a[j].v;

    db alp_1 = a[i].d;
    db alp_2 = a[j].d;

    db u = x_1 - x_2;
    db k = y_1 - y_2;

    db m = (sin(alp_1) * v_1 - sin(alp_2) * v_2);
    db p = (cos(alp_1) * v_1 - cos(alp_2) * v_2);

    db hs_a = m*m + p*p;
    db hs_b = 2 * (u * m + k * p);
    db hs_c = u*u + k*k - r*r;

    if (hs_c <= eps) return 0;
    if (fabs(hs_a) <= eps) return 1e18;
    db delta = hs_b * hs_b - 4 * hs_a * hs_c;
    if (delta < -eps) return 1e18;

    db ng_1 = ((-hs_b + sqrt(delta)) / (2 * hs_a));
    db ng_2 = ((-hs_b - sqrt(delta)) / (2 * hs_a));

    if (ng_1 < eps) ng_1 = (db) 1e18;
    if (ng_2 < eps) ng_2 = (db) 1e18;

    return min(make_round(ng_1), make_round(ng_2));
}
int main() {
    fastio;
    #define test "P539"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n >> r;
        fto(i, 1, n) {
            cin >> a[i].x >> a[i].y >> a[i].d >> a[i].v;
            a[i].d = a[i].d * PI / 180;
        }
        ans = -1;
        fto(i, 1, n-1) {
            fto(j, i+1, n) {
                ll res = solve(i, j);
                if (res == 1e18) continue;
                if (ans == -1) ans = res;
                else if (ans > res) ans = res;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}