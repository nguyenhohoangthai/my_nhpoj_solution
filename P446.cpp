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
ll n, k, m, x, y, a, b;
int main() {
    fastio;
    if (fopen("P446.inp", "r")) {
        freopen("P446.inp", "r", stdin);
        freopen("P446.out", "w", stdout);
    }
    cin >> n >> m >> k >> x >> y;
    b = (k*m*x - n) / (m * (x - y));
    a = k - b;
    if (a < 0 || b < 0) {
        cout << -1 << "\n";
        return 0;
    }
    if ((m * a * x + m * b * y) == n) cout << a << " " << b << "\n";
    else cout << "−1";
    return 0;
}