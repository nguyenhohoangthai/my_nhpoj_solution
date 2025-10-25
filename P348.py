#include<bits/stdc++.h>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define MASK(i) ((1LL) << (i))
using namespace std;
const int LOG = 18;
const int maxN = 100005;
int st[LOG][maxN], table[maxN], n, k, a[maxN];
void init() {
    fto(i, 1, n) st[0][i] = a[i];

    fto(j, 1, LOG - 1) {
        fto(i, 1, n - MASK(j) + 1) {
            st[j][i] = min(st[j-1][i], st[j-1][i + MASK(j-1)]);
        }
    }

    table[1] = 0;
    fto(i, 2, n) table[i] = table[i >> 1] + 1;
}
int query(int l, int r) {
    if (l > r) return 0;
    int j = table[r - l + 1];
    return min(st[j][l], st[j][r - MASK(j) + 1]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i];
    init();
    fto(i, k, n) {
        cout << query(i-k+1, i) << "\n";
    }
}