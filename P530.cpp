#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T, n, m, f[105][10005];
pair<int, int> a[105];
int dp(int i, int r) {
    if (i > n) return (r == m);
    if (f[i][r] != -1) return f[i][r];
    int res = 0;
    res = max(res, dp(i+1, r + a[i].first));
    res = max(res, dp(i+1, r + a[i].second));
    return f[i][r] = res;
}
int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
        memset(f, -1, sizeof (f));
        cout << (dp(1, 0) ? "YES" : "NO") << "\n";
    }
}