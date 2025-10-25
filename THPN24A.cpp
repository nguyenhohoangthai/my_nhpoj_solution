/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define ord(a) a - '0' - 48
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
long long n, k, l, r, sum, f[100], ans;
string s;
int main() {
    fastio;
    cin >> n >> k;
    cin >> s;
    l = 0;
    r = 0;
    while (l <= r && r < n) {
        sum -= f[ord(s[r])] * f[ord(s[r])];
        ++f[ord(s[r])];
        sum += f[ord(s[r])] * f[ord(s[r])];
        while (sum > k) {
            sum -= f[ord(s[l])] * f[ord(s[l])];
            --f[ord(s[l])];
            sum += f[ord(s[l])] * f[ord(s[l])];
            ++l;
        }
        ans += (r - l + 1);
        ++r;
    }
    cout << ans << "\n";
    return 0;
}