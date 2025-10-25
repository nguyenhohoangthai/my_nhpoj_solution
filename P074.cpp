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
int n, x, y, z, a[maxN], b[maxN], ans;
pii sa[maxN], sb[maxN];
bool cmp1(pii t, pii k) {
    return t.ff < k.ff;
}
bool cmp2(pii t, pii k) {
    return t.ss < k.ss;
}
int get_large(int x) {
    int low = 1;
    int high = n;
    int p = 0;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (sb[mid].ss < x) {
            p = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return p;
}
int get_small(int x) {
    int low = 1;
    int high = n;
    int p = n+1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (sa[mid].ff > x) {
            p = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return n - p + 1;
}
int main() {
    fastio;
    if (fopen("P074.inp", "r")) {
        freopen("P074.inp", "r", stdin);
        freopen("P074.out", "w", stdout);
    }
    cin >> n >> x >> y >> z;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n) cin >> b[i];
    fto(i, 1, n) sa[i] = {a[i], b[i]}, sb[i] = {a[i], b[i]};
    sort(sa+1, sa+n+1, cmp1);
    sort(sb+1, sb+n+1, cmp2);
    fto(i, 0, 1000000) {
        int cnt_1 = get_large(i);
        int cnt_2 = get_small(i);
        maximize(ans, cnt_1 * z + cnt_2 * y + (n - cnt_1 - cnt_2) * x);
    }
    cout << ans << "\n";
    return 0;
}