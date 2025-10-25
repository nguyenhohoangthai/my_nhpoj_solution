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
int n, m, ans;
vector<int> a, b, t_a, t_b;
int main() {
    fastio;
    #define test "P540"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    fto(i, 0, n-1) cin >> a[i];
    fto(i, 0, m-1) cin >> b[i];
    t_a = a;
    t_b = b;
    while (1) {
        bool ok = true;
        fto(i, 0, min(sz(a), sz(b)) - 1) {
            if (a[i] == 2 && b[i] == 2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = max(sz(a), sz(b));
            break;
        }
        a.insert(a.begin(), 1);
    }
    a = t_a;
    b = t_b;
    while (1) {
        bool ok = true;
        fto(i, 0, min(sz(a), sz(b)) - 1) {
            if (a[i] == 2 && b[i] == 2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = min(ans, max(sz(a), sz(b)));
            break;
        }
        b.insert(b.begin(), 1);
    }
    cout << ans << "\n";
    return 0;
}