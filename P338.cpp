/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fat(i, a) for (auto i : a)
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, a[205], total, f[205][100005];
int dp(int i, long long s) {
    if (s > total || i > n) return 0;
    if (s == total) return 1;
    if (f[i][s] != -1) return f[i][s];
    return f[i][s] = max(dp(i+1, s+a[i]), dp(i+1, s));
}
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i];
        total += a[i];
    }
    if (total & 1) cout << "false\n";
    else {
        mem(f, -1);
        total >>= 1;
        cout << ((dp(1, 0)) ? "true" : "false");
    }
    return 0;
}