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
int n, k, a[maxN];
int main() {
    fastio;
    if (fopen("P499.inp", "r")) {
        freopen("P499.inp", "r", stdin);
        freopen("P499.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, k) {
        int l, r; cin >> l >> r;
        a[l] += 1;
        a[r+1] -= 1;
    }
    fto(i, 1, n) a[i] += a[i-1];
    vector<int> vt;
    fto(i, 1, n) vt.pb(a[i]);
    sort(vt.begin(), vt.end());
    cout << vt[sz(vt) >> 1] << "\n";
    return 0;
}