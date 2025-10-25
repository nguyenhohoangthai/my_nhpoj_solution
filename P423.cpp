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
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int T, n, a[maxN];
int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n;
        fto(i, 1, n) cin >> a[i];
        sort(a+1, a+n+1);
        int cnt = 1;
        int c_1 = 0;
        string ans = "NO\n";
        a[n+1] = a[n] + 4;
        fto(i, 2, n + 1) {
            if (a[i] != a[i-1]) {
                if (cnt >= 4) {
                    ans = "YES\n";
                    break;
                }
                if (cnt >= 2) {
                    if (c_1 == 0) c_1 = 1;
                    else {
                        ans = "YES\n";
                        break;
                    }
                }
                cnt = 1;
            }
            else ++cnt;
        }
        cout << ans;
    }
    return 0;
}