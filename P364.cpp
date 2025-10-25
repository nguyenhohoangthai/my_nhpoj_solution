/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, mx_cnt, ans, prv;
set<int> a;
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) {
        int x; cin >> x;
        a.insert(x);
    }
    prv = -oo;
    for (auto x : a) {
        if (x == prv + 1) ++mx_cnt;
        else {
            ans = max(ans, mx_cnt);
            mx_cnt = 1;
        }
        prv = x;
    }
    ans = max(ans, mx_cnt);
    cout << ans << "\n";

    return 0;
}