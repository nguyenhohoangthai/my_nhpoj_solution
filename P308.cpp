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
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
vector<pair<int, int>> adj[100005];
int n, m, s, t, d[100005], visited[100005];
void dijkstra(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({0, s});
	while (!Q.empty()) {
		pair<int, int> t = Q.top();
		Q.pop();
		int leaf = t.ss;
		int dis = t.ff;
		if (visited[leaf] == 0) {
			for (auto x : adj[leaf]) {
				int v = x.ff;
				int kc = x.ss;
				d[v] = min(d[v], d[leaf] + kc);
				Q.push({d[v], v});
			}
		}
		visited[leaf] = 1;
	}
}
int main() {
    fastio;
    cin >> n >> m >> s >> t;
    fto(i, 1, m) {
    	int u, v, w; cin >> u >> v >> w;
    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }
    memset(d, oo, sizeof d);
    d[s] = 0;
    dijkstra(s, t);
    cout << d[t] << "\n";
    return 0;
}