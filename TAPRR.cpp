#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fllto(i, a, b) for (long long i = a; i <= b; ++i)
#define flldto(i, a, b) for (long long i = a; i >= b; --i)
#define fvt(i, g) for (int i : g)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define open(a) freopen(a".inp", "r", stdin); freopen(a".out", "w", stdout);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text 3\Packages\User
int n, m, parent[100005];

int find(int u) {
    if (u == parent[u]) return u;
    int tmp = find(parent[u]);
    return parent[u] = tmp;
}
void union_set(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[v] = u;
}

void make_set() {
    fto(i, 1, n) parent[i] = i;
}

int main(){
    fastio;
    cin >> n >> m;
    make_set();
    while (m--) {
        int t, i, j; cin >> t >> i >> j;
        if (t == 1) union_set(i, j);
        else {
            int p_i = find(i);
            int p_j = find(j);
            if (p_i == p_j) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}