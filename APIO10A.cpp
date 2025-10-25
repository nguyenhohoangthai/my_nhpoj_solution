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
#define PI acos(-1)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
const int INF = 1e18;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};


struct Line {
int a, b;
    Line(int a = 0, int b = -INF) : a(a), b(b) {}
    int get(int x) {
        return a * x + b;
    }
};

struct LiChao {
vector<Line> tr;
    vector<int> xs;

    void init(vector<int> coords) {
        xs = coords;
        tr.assign(4*sz(xs)+5, Line());
    }

    void add(Line nw, int id, int l, int r) {
        int mid = (l + r) >> 1;

        int xl=xs[l];
        int xm=xs[mid];
        int xr=xs[r];

        bool left = nw.get(xl) > tr[id].get(xl);
        bool midBetter = nw.get(xm) > tr[id].get(xm);
        if (midBetter) swap(tr[id], nw);
        if (l == r) return;
        if (left != midBetter) add(nw, id << 1, l, mid);
        else add(nw, id << 1 | 1, mid+1, r);
    }
    int query(int x, int id, int l, int r) {
        int val = tr[id].get(x);
        if (l == r) return val;
        int mid = (l + r) >> 1;
        if (x <= xs[mid]) return max(val, query(x, id << 1, l, mid));
        else return max(val, query(x, id << 1 | 1, mid+1, r));
    }
};

int T, n, a, b, c;
int x[maxN], dp[maxN];

signed main() {
    fastio;
    #define test "APIO10A"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }

    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a >> b >> c;

        fto(i, 1, n) cin >> x[i];

        vector<int> coords;
        coords.pb(0);

        fto(i, 1, n) {
            x[i] += x[i-1];
            coords.pb(x[i]);
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        int mx_r = sz(coords) - 1;

        LiChao lichao;
        lichao.init(coords);

        dp[0] = 0;
        lichao.add(Line(-2*a*x[0], dp[0] + a*x[0]*x[0] - b*x[0]), 1, 0, mx_r);

        fto(i, 1, n) {
            dp[i] = lichao.query(x[i], 1, 0, mx_r) + a*x[i]*x[i] + b*x[i] + c;
            lichao.add(Line(-2*a*x[i], dp[i] + a*x[i]*x[i] - b*x[i]), 1, 0, mx_r);
        }

        cout << dp[n] << "\n";
    }
}