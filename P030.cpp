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
int n, x, ans;
vector<int> a;
void pre() {
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            a.pb(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) a.pb(x);
}
int main() {
    fastio;
    #define test "P030"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> x;
    if (x == 1) {
        cout << n << "\n";
        return 0;
    }
    pre();

    int mx = sz(a);

    fto(mask, 1, MASK(mx) - 1) {
        int prod = 1;
        for (int sub = mask; sub; sub &= (sub - 1)) {
            int i = __builtin_ctz(sub);
            prod *= a[i];
        }
        if (bit_count(mask) & 1) ans += n / prod;
        else ans -= n / prod;
    }

    cout << n - ans << "\n";
    return 0;
}