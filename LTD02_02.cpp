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
const double EPS = 1e-10;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int T, ans;
double a, b, c, d, delta, a2, b2, c2, x1, x2;
double f(double x) {
    return a*x*x*x + b*x*x + c*x + d;
}
int main() {
    fastio;
    #define test "LTD02_02"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        a2 = a * 3;
        b2 = b * 2;
        c2 = c;

        delta = b2*b2 - 4 * a2 * c2;
        x1 = (-b2 + sqrt(delta)) / (2*a2);
        x2 = (-b2 - sqrt(delta)) / (2*a2);

        double prod = f(x1) * f(x2);

        if (prod < 0) ans = 3;
        else if (prod == 0) ans = 2;
        else ans = 1;

        cout << ans << "\n";
    }
    return 0;
}