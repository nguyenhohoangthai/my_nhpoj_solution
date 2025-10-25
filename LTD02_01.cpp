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
const long long oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
long long n, gt[1000005], ans;
long long lt(long long a, long long b) {
    if (b == 0) return 1LL;
    if (b & 1) return (a * lt(a, b-1)) % oo;
    long long t = lt(a, b/2);
    return (t * t) % oo;
}
long long chia(long long a, long long b) {
    return (a * lt(b, oo - 2)) % oo;
}
int main() {
    fastio;
    cin >> n;
    gt[1] = 1;
    fto(i, 2, n) gt[i] = (gt[i-1] * i) % oo;
    ans = gt[n];
    fto(i, 2, n) {
        if (i & 1) ans = (ans + chia(gt[n], gt[i])) % oo;
        else ans = (ans - chia(gt[n], gt[i]) + oo) % oo;
    }
    cout << ans << "\n";
    return 0;
}