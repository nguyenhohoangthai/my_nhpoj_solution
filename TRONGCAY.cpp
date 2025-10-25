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
const db EPS = 1e-9;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct point {
    db x, y;
    point(db x, db y) : x(x), y(y) {}
    point() {}
};
ll cross(point A, point B, point C) {
    return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
};

int inside(point A, point B, point C, point P) {
    ll c1 = cross(A, B, P);
    ll c2 = cross(B, C, P);
    ll c3 = cross(C, A, P);
    return ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0));
}

point m, n, k;
int ans, mn_x, mx_x, mn_y, mx_y;
int main() {
    fastio;
    #define test "TRONGCAY"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> m.x >> m.y;
    cin >> n.x >> n.y;
    cin >> k.x >> k.y;

    mn_x = min({m.x, n.x, k.x});
    mx_x = max({m.x, n.x, k.x});
    mn_y = min({m.y, n.y, k.y});
    mx_y = max({m.y, n.y, k.y});

    fto(i, mn_x, mx_x) {
        fto(j, mn_y, mx_y) {
            ans += inside(m, n, k, point(i, j));
        }
    }
    cout << ans << "\n";
    return 0;
}