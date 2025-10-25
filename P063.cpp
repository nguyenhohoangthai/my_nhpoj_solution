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
int n, k, f[maxN];
vector<vector<int>> a;
vector<int> pos[1005];
int main() {
    fastio;
    if (fopen("P063.inp", "r")) {
        freopen("P063.inp", "r", stdin);
        freopen("P063.out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(k);
    fto(i, 0, k-1) {
        a[i].resize(n);
        fto(j, 0, n-1) {
            cin >> a[i][j];
            --a[i][j];
            pos[a[i][j]].pb(j);
        }
    }
    fto(i, 0, n-1) f[i] = 1;
    int ans = 0;
    fto(i, 0, n-1) {
        fto(j, 0, i-1) {
            bool ok = true;
            fto(l, 0, k-1) {
                if (pos[a[0][i]][l] < pos[a[0][j]][l]) {
                    ok = false;
                    break;
                }
            }
            if (ok) maximize(f[i], f[j] + 1);
        }
        maximize(ans, f[i]);
    }
    cout << ans << "\n";
    return 0;
}