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
#pragma GCC optimize("O3", "unroll-loops")
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
const int maxN = 300005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, k, a[maxN], used[maxN];
vector<pii> ans;

int main() {
    fastio;
    #define test "sinh"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> m >> k;
    fto(i, 1, n+m) cin >> a[i];

    fto(i, 1, n+m) {
        if (used[i]) continue;
        used[i] = 1;
        fto(j, i, min(n+m, i+k+1)) {
            if (a[i] == a[j] || used[j]) continue;
            used[j] = 1;
            if (a[i] == 0) ans.pb(make_pair(i, j));
            else ans.pb(make_pair(j, i));
            break;
        }
    }
    sort(ans.begin(), ans.end());
    cout << sz(ans) << "\n";
    for (auto x : ans) cout << x.ff << " " << x.ss << "\n";
    return 0;
}