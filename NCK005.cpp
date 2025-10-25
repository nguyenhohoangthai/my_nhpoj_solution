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
const int LOG = 18;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n;
ll s, x, a[maxN], st[LOG][maxN], table[maxN], ans;
vector<pair<ll, int>> pos;

void init() {
    fto(i, 1, n) st[0][i] = a[i];

    fto(j, 1, LOG - 1) {
        fto(i, 1, n - MASK(j) + 1) {
            st[j][i] = max(st[j-1][i], st[j-1][i + MASK(j-1)]);
        }
    }

    table[1] = 0;
    fto(i, 2, n) table[i] = table[i >> 1] + 1;
}

ll query(int l, int r) {
    if (l > r) return 0;
    int j = table[r - l + 1];
    return max(st[j][l], st[j][r - MASK(j) + 1]);
}

int get_left(int idx, int cmp) {
    int low = idx;
    int high = sz(pos) - 1;
    int p = -1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (pos[mid].ff >= cmp) {
            p = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return p;
}
int get_right(int idx, int cmp) {
    int low = idx;
    int high = sz(pos) - 1;
    int p = sz(pos);
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (pos[mid].ff > cmp) {
            p = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    --p;
    if (p > 0 && pos[p].ff == cmp) return p;
    return -1;
}
int get_bound(int l, int r, int cmp) {
    int low = l;
    int high = r;
    int p = -1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (pos[mid].ss >= cmp) {
            p = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return p;
}
int main() {
    fastio;
    #define test "sinh"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> s >> x;
    fto(i, 1, n) cin >> a[i];

    init();

    fto(i, 1, n) {
        a[i] += a[i-1];
        pos.pb(make_pair(a[i], i));
    }

    sort(pos.begin(), pos.end(), [](const pair<ll, int> x, const pair<ll, int> y) {
        if (x.ff == y.ff) return x.ss < y.ss;
        return x.ff < y.ff;
    });


    fto(i, 0, sz(pos) - 1) {
        ll need = s + a[pos[i].ss - 1];
        int l = get_left(i, need);
        int r = get_right(i, need);
        if (l == -1 || r == -1) continue;

        l = get_bound(l, r, pos[i].ss);
        if (l == -1) continue;
        int low = l;
        int high = r;
        int p = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (query(pos[i].ss, pos[mid].ss) <= x) {
                p = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        if (p != -1 && query(pos[i].ss, pos[p].ss) == x) ans += (p - l + 1);
    }
    cout << ans << "\n";
    return 0;
}