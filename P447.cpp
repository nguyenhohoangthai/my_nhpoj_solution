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
int n, k, a[maxN], ans;
vector<pii> cnt;
int check(int x) {
    int res = 0;
    fto(i, 1, n) {
        if (a[i] >= x) ++res;
    }
    return (res <= k);
}
int main() {
    fastio;
    if (fopen("P447.inp", "r")) {
        freopen("P447.inp", "r", stdin);
        freopen("P447.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    int low = 1;
    int high = oo;
    ans = oo;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}