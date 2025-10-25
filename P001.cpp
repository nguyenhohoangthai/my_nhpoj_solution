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
int n, a[3*maxN], f[3*maxN];
vector<int> pos[3 * maxN];
vector<int> tree, tree_2;
void update(int node, int l, int r, int u, int x) {
    if (u > r || u < l) return;
    if (l == r) {
        tree[node] = x;
        return;
    }
    int mid = (l + r) >> 1;
    update(node*2, l, mid, u, x);
    update(node*2+1, mid+1, r, u, x);
    tree[node] = min(tree[2*node], tree[2*node+1]);
    return;
}
int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return oo;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return min(query(node*2, l, mid, u, v), query(node*2+1, mid+1, r, u, v));
}
int main() {
    fastio;
    cin >> n;
    tree.resize(12*maxN, oo);
    fto(i, 1, n) f[i] = oo;
    fto(i, 1, n) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    if (sz(pos[a[1]]) == 1 || sz(pos[a[n]]) == 1) {
        cout << 0 << "\n";
        return 0;
    }
    f[1] = 0;
    update(1, 1, n, 1, 0);
    fto(i, 2, n) {
        // truong hop no la duy nhat
if (pos[a[i]].size() == 1) {
            update(1, 1, n, i, oo);
            f[i] = oo;
            continue;
        }
        // truong hop la thang dung dau co the chon bat ki mot thang truoc
if (pos[a[i]].front() == i) {
            f[i] = query(1, 1, n, 1, i - 1) + (i < n);
            update(1, 1, n, i, f[i]);
            continue;
        }
        // tim vi tri j sao cho a[i] == a[j] gan nhat
int low = 0;
        int high = sz(pos[a[i]]) - 1;
        int p = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (pos[a[i]][mid] < i) {
                p = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        p = pos[a[i]][p];
        // neu no la thang dung cuoi
if (i != n && pos[a[i]].back() == i) {
            f[p] = oo;
            update(1, 1, n, p, oo);
            continue;
        }
        f[i] = query(1, 1, n, 1, i-1) + (i < n);
        update(1, 1, n, i, f[i]);
        f[p] = oo;
        update(1, 1, n, p, oo);
        // fto(j, 1, n) cout << f[j] << " ";
// cout << "\n";
    }
    cout << (f[n] == oo ? 0 : f[n] + 1) << "\n";
    return 0;
}