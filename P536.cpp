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
int k;
double sum[maxN*10];
bool check(int x, int y) {
     ll r = (sum[y] - sum[x-1] + 1);
     return (r >= k);
}
pair<int, int> ans;
int main() {
    fastio;
    #define test "P536"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> k;
    fto(a, 1, (int) 1e6) sum[a] = sum[a-1] + 1.0 * log10(a);
    for (int a = 1; a <= (int) 1e6; ++a) {
        int low = a;
        int high = (int) 1e6;
        int p = a;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (check(a, mid)) {
                p = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        if ((ll) (sum[p] - sum[a-1] + 1) == k) {
            if ((p - a < ans.ss - ans.ff) || (ans.ff == 0 && ans.ss == 0)) ans = make_pair(a, p);
        }
    }
    cout << ans.ff << " " << ans.ss << "\n";
    return 0;
}