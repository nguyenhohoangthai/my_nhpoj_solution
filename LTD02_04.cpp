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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, k, x, y, a[200005], visited[200005], f[200005];
vector<int> d[200005];
vector<int> path;
void dp(int i) {
	if (visited[i] == 1) return;
	path.pb(i);
	visited[i] = 1;
	dp(d[i][0]);
}
int main() {
    fastio;
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n) {
    	cin >> x >> y;
    	if (x == y) f[x] = y;
    	d[x].pb(y);
    }
    fto(i, 1, n) {
    	if (!visited[i] && i != d[i][0]) {
    		dp(i);
            fto(i, 1, path.size()) {
                int d = (i+k) % path.size();
                if (d > 0) f[path[d-1]] = path[i-1];
                else if (d == 0) f[path[path.size() - 1]] = path[i-1];

            }
            path.clear();
    	}
    }
    // for (auto t : path) cout << t << " ";
// cout << "\n";
// fto(i, 1, path.size()) {
//     int d = (i+k) % path.size();
//     if (d > 0) f[path[d-1]] = path[i-1];
//     else if (d == 0) f[path[path.size() - 1]] = path[i-1];
// }
    fto(i, 1, n) {
        cout << a[f[i]] << " ";
    }
    return 0;
}