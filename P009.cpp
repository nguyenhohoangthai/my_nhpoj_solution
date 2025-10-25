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
#define ll long long
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
int n, a[maxN], b[maxN], num, mx;
ll sum[maxN], prod[maxN];
pii c[maxN];
ll ans;
int get_left(int x) {
    int low = 1;
    int high = n;
    int p = -1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (c[mid].ff < x) {
            p = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return p;
}
int get_right(int x) {
    int low = 1;
    int high = n;
    int p = -1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (c[mid].ff > x) {
            p = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return p;
}
ll solve(int l, int r, ll x) {
    ll res = 0;
    if (l != -1) res += x * sum[l] - prod[l];
    if (r != -1) res += prod[n] - prod[r-1] - x * (sum[n] - sum[r-1]);
    return res;
}
int main() {
    fastio;
    if (fopen("nsadj.inp", "r")) {
        freopen("nsadj.inp", "r", stdin);
        freopen("nsadj.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i], maximize(mx, a[i]);
    fto(i, 1, n) cin >> b[i];
    fto(i, 1, n) {
        c[i] = make_pair(a[i], b[i]);
    }
    sort(c+1, c+n+1);
    fto(i, 1, n) {
        sum[i] = sum[i-1] + 1LL*c[i].ss;
        prod[i] = prod[i-1] + (1LL*c[i].ff) * (1LL*c[i].ss);
    }
    ans = 1e18;
    fto(i, 0, mx) {
        int _left = get_left(i);
        int _right = _left + 1;
        ll t = solve(_left, _right, 1LL*i);
        if (ans > t) {
            ans = t;
            num = i;
        }
    }
    cout << num << " " << ans << "\n";
    return 0;
}