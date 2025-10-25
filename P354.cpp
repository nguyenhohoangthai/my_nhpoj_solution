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
int n, elem, parent[maxN];
long long ans;
struct tupe {
int u, v, w;
};
struct node {
int id, x, y;
};
node a[maxN], b[maxN];
vector<tupe> adj;
void make_set() {
	fto(i, 1, n) parent[i] = i;
}
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}
int union_set(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	parent[b] = a;
	return 1;
}
int cmp(tupe a, tupe b) {
	return a.w < b.w;
}
int cmp_x(node a, node b) {
	return a.x < b.x;
}
int cmp_y(node a, node b) {
	return a.y < b.y;
}
int main() {
    fastio;
    cin >> n;
    elem = n;
    make_set();
    fto(i, 1, n) {
    	cin >> a[i].x >> a[i].y;
    	b[i].x = a[i].x; b[i].y = a[i].y;
    	a[i].id = i;
    	b[i].id = i;
    }
    sort(a+1, a+n+1, cmp_x);
    sort(b+1, b+n+1, cmp_y);
    fto(i, 1, n) {
    	if (i < n) {
    		tupe mytupe = {a[i].id, a[i+1].id, min(abs(a[i].x - a[i+1].x), abs(a[i].y - a[i+1].y))};
    		adj.pb(mytupe);
    		tupe mytupe1 = {a[i+1].id, a[i].id, min(abs(a[i].x - a[i+1].x), abs(a[i].y - a[i+1].y))};
    		adj.pb(mytupe1);
    		tupe mytupe2 = {b[i].id, b[i+1].id, min(abs(b[i].x - b[i+1].x), abs(b[i].y - b[i+1].y))};
    		adj.pb(mytupe2);
    		tupe mytupe3 = {b[i+1].id, b[i].id, min(abs(b[i].x - b[i+1].x), abs(b[i].y - b[i+1].y))};
    		adj.pb(mytupe3);
    	}
    	else {
    		tupe mytupe = {a[i].id, a[i-1].id, min(abs(a[i].x - a[i-1].x), abs(a[i].y - a[i-1].y))};
    		adj.pb(mytupe);
    		tupe mytupe1 = {a[i-1].id, a[i].id, min(abs(a[i].x - a[i-1].x), abs(a[i].y - a[i-1].y))};
    		adj.pb(mytupe1);
    		tupe mytupe2 = {b[i].id, b[i-1].id, min(abs(b[i].x - b[i-1].x), abs(b[i].y - b[i-1].y))};
    		adj.pb(mytupe2);
    		tupe mytupe3 = {b[i-1].id, b[i].id, min(abs(b[i].x - b[i-1].x), abs(b[i].y - b[i-1].y))};
    		adj.pb(mytupe3);
    	}
    }
    sort(adj.begin(), adj.end(), cmp);
    for (auto e : adj) {
    	if (!union_set(e.u, e.v)) continue;
    	ans += e.w;
    }
    cout << ans << "\n";
    return 0;
}