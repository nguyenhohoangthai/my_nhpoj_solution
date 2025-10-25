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
int n, q, a[100005], tree[400005];
//1 2 3 4 5
void init(int node, int l, int r) {
 if (l == r) {
  tree[node] = a[l];
  return;
 }
 int mid = (l + r) / 2;
 init(2*node, l, mid);
 init(2*node + 1, mid+1, r);
 tree[node] = tree[2*node] ^ tree[2*node + 1];
}
void update(int node, int l, int r, int i, int x) {
 if (l == r) {
     if (l != i) return;
     tree[node] = tree[node]^ x;
     return;
 }
 if (i < l || i > r) return;
 int mid = (l + r) / 2;
 update(2*node, l, mid, i, x);
 update(2*node + 1, mid+1, r, i, x);
 tree[node] = tree[node*2] ^ tree[node*2+1];
}
int get_xor(int node, int l, int r, int i, int j) {
 if (i > r || j < l) return 0;
 if (i <= l && r <= j) return tree[node];
 int mid = (l + r) / 2;
 int g_1 = get_xor(2*node, l, mid, i, j);
 int g_2 = get_xor(2*node + 1, mid+1, r, i, j);
 return g_1^g_2;
}
int main() {
    fastio;
    cin >> n >> q;
    fto(i, 1, n) cin >> a[i];
    init(1, 1, n);
    while (q--) {
     int type, i, j; cin >> type >> i >> j;
     if (type == 1) update(1, 1, n, i, j);
     else cout << get_xor(1, 1, n, i, j) << "\n";
    }
    return 0;
}