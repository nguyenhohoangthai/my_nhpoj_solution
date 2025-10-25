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
int n, a[205][205], f[205][205];
int dp(int i, int j) {
    if (i > n) return 0;
    if (f[i][j] != -1) return f[i][j];
    return f[i][j] = max(dp(i+1, j) + a[i][j], dp(i+1, j+1) + a[i][j]);
}
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) {
        fto(j, 1, i) cin >> a[i][j];
    }
    mem(f, -1);
    cout << dp(1, 1) << "\n";
    return 0;
}