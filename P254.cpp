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
int n, a[20005], c, dis;
vector<int> b, ans;
int check_1(vector<int> x, vector<int> y) {
    dis = x[0] - y[0];
    fto(i, 1, sz(x) - 1) {
        if (x[i] - y[i] != dis) return 0;
    }
    return 1;
}
void check(int p) {
    vector<int> x;
    fto(i, p, p+c-1) x.pb(a[i]);
    sort(x.begin(), x.end());
    if (check_1(x, b)) ans.pb(p);
}
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    cin >> c;
    fto(i, 1, c) {
        int x; cin >> x;
        b.pb(x);
    }
    sort(b.begin(), b.end());
    if (n >= c) fto(i, 1, n-c+1) check(i);
    cout << sz(ans) << "\n";
    for (auto x : ans) cout << x << "\n";
    return 0;
}