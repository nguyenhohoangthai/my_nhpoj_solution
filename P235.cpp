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
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int T;
ll l, r, num, sum[10], ans;
int main() {
    fastio;
    #define test "TONG"
if (fopen(test".INP", "r")) {
        freopen(test".INP", "r", stdin);
        freopen(test".OUT", "w", stdout);
    }
    cin >> T;
    fto(i, 1, 9) sum[i] = sum[i-1] + i;
    while (T--) {
        cin >> l >> r;
        num = r - l + 1;
        num -= (10 - (l % 9)) % 9;
        num -= r % 9;
        ans = 5 * num;

        if (l % 9 == 0) ans += (sum[9] - sum[8]);
        else if (l % 9 > 1) ans += sum[9] - sum[(l % 9) - 1];

        ans += sum[r % 9];
        cout << ans << "\n";
    }
    return 0;
}