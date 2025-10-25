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
const int maxN = 1000005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct node {
int x1, y1, x2, y2;
};
int n, k, f[1005][1005], ans;
node a[maxN];
int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        --f[a[i].x1][a[i].y2];
        ++f[a[i].x2][a[i].y2];
        ++f[a[i].x1][a[i].y1];
        --f[a[i].x2][a[i].y1];
    }
    fto(i, 0, 1000) {
        fto(j, 0, 1000) {
            f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
            ans += (f[i][j] == k);
        }
    }
    // fto(i, 1, 10) {
//     fto(j, 1, 10) cout << f[i][j] << " ";
//     cout << "\n";
// }
cout << ans << "\n";
    return 0;
}