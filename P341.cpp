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
string s;
int n, f[1005], len[1005], ans;
int main() {
    fastio;
    cin >> s;
    n = sz(s);
    if (s[0] == 'a') {
        f[0] = 1;
        len[0] = 1;
    }
    fto(i, 1, n-1) {
        f[i] = 1;
        if (s[i] == 'a') len[i] = 1;
        fdto(j, i-1, 0) {
            if (s[j] <= s[i]) {
                if (s[i] == 'e' && len[j] >= 4) {
                    len[i] = 5;
                    f[i] = max(f[i], f[j] + 1);
                }
                if (s[i] == 'd' && len[j] >= 3 && len[j] <= 4) {
                    len[i] = 4;
                    f[i] = max(f[i], f[j] + 1);
                }
                if (s[i] == 'c' && len[j] >= 2 && len[j] <= 3) {
                    len[i] = 3;
                    f[i] = max(f[i], f[j] + 1);
                }
                if (s[i] == 'b' && len[j] >= 1 && len[j] <= 2) {
                    len[i] = 2;
                    f[i] = max(f[i], f[j] + 1);
                }
                if (s[i] == 'a' && len[j] == 1) {
                    len[i] = 1;
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
    }
    // fto(i, 0, n-1) cout << f[i] << " ";
// cout << "\n";
// fto(i, 0, n-1) cout << len[i] << " ";
// cout << "\n";
    fto(i, 0, n-1) {
        if (len[i] == 5) ans = max(ans, f[i]);
    }
    cout << ans << "\n";
    return 0;
}