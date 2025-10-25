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
long long k, a[maxN], q, l, r, tree[4*maxN], last;
void init(int node, int l, int r) {
    if (l >= r) {
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(node*2, l, mid);
    init(node*2+1, mid + 1, r);
    tree[node] = tree[2*node] ^ tree[2*node+1];
}
long long query(int node, int l, int r, int u, int v) {
    if (u > r || v < l || l > r || u > v) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    long long q_1 = query(2 * node, l, mid, u, v);
    long long q_2 = query(2 * node + 1, mid+1, r, u, v);
    return (long long) (q_1 ^ q_2);
}
int main() {
    fastio;
    cin >> k;
    fto(i, 1, k) {
        cin >> a[i];
        if (last == 0) last = a[i];
        else last ^= a[i];
    }
    ++k;
    a[k] = last;
    init(1, 1, k);
    cin >> q;
    while (q--) {
        cin >> l >> r;
        if (r <= k) cout << query(1, 1, k, l, r) << "\n";
        else {
            long long t_1, t_2;
            if (l <= k && r > k) {
                t_1 = query(1, 1, k, l, k);
                if (r % k != 0) t_2 = query(1, 1, k, 1, r % k);
                else t_2 = query(1, 1, k, 1, k);
                cout << (t_1 ^ t_2) << "\n";
            }
            else {
                long long l_bound = l % k;
                long long r_bound = r % k;
                if (l_bound <= r_bound && l_bound > 0 && r_bound > 0) cout << query(1, 1, k, l_bound, r_bound) << "\n";
                else if (l_bound > r_bound && l_bound > 0 && r_bound > 0) cout << (query(1, 1, k, l_bound, k) ^ query(1, 1, k, 1, r_bound)) << "\n";
                else if (l_bound == 0 || r_bound == 0) {
                    if (l_bound == r_bound) cout << a[k] << "\n";
                    else {
                        if (r_bound == 0) cout << query(1, 1, k, l_bound, k) << "\n";
                        else cout << (query(1, 1, k, 1, r_bound) ^ a[k]) << "\n";
                    }
                }
            }
        }
    }
    return 0;
}