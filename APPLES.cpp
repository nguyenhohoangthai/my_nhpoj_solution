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
struct point {
int x, y, idx;
    point() {}
    point(int x, int y, int idx) : x(x), y(y), idx(idx) {}
};
int n, root;
point a[maxN];
vector<pair<double, int>> pos;
double slope(point x) {
    if (x.x == a[1].x) return 90.0;
    double goc = (180 * atan(1.0 * (x.y - a[1].y) / (1.0 * (x.x - a[1].x))) / PI);
    if (goc < 0) return 180 + goc;
    return goc;
}
int main() {
    fastio;
    #define test "APPLES"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        a[i].idx = i;
    }

    sort(a+1, a+n+1, [] (const point x, const point y) {
        if (x.y == y.y) return x.x < y.x;
        return x.y < y.y;
    });

    root = a[1].idx;

    fto(i, 2, n) pos.pb(make_pair(slope(a[i]), a[i].idx));

    sort(pos.begin(), pos.end(), [] (const pair<double, int> x, const pair<double, int> y) {
        return x.ff < y.ff;
    });

    cout << root << " " << pos[(n-1) >> 1].ss << "\n";

    return 0;
}