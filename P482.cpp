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
int n, m, k, a[11][11], ans[101][101], nxt_row, nxt_col;
int main() {
    fastio;
    if (fopen("P482.inp", "r")) {
        freopen("P482.inp", "r", stdin);
        freopen("P482.out", "w", stdout);
    }
    cin >> n >> m >> k;
    fto(i, 1, n) {
        string s; cin >> s;
        fto(j, 1, m) a[i][j] = (s[j-1] - '0');
    }
    nxt_row = nxt_col = 1;
    fto(i, 1, n) {
        fto(j, 1, m) {
            fto(n_i, nxt_row, nxt_row + k - 1) {
                fto(n_j, nxt_col, nxt_col + k - 1) {
                    ans[n_i][n_j] = a[i][j];
                }
            }
            nxt_col += k;
        }
        nxt_row += k;
        nxt_col = 1;
    }
    fto(i, 1, n*k) {
        fto(j, 1, m*k) cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}