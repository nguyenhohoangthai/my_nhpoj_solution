#include <bits/stdc++.h>
using namespace std;
int m, n, T, k[55], a[55][1005], f[55][1005];
int ans;
void dp(int i, int c) {
    if (c > m) return;
    if (i > n) {
      ans = max(ans, c);
      return;
    }
    if (f[i][c] == 1) return;
    for (int j = 1; j <= k[i]; ++j) dp(i+1, c + a[i][j]);
    f[i][c] = 1;
}
int main(){
    cin >> T;
    while(T--){
        cin >> m >> n;
        for (int i = 1; i <= n; ++i) {
          cin >> k[i];
          for (int j = 1; j <= k[i]; ++j) cin >> a[i][j];
        }
        for (int i = 1; i <= n; ++i) {
          for (int j = 0; j <= m; ++j) f[i][j] = 0;
        }
        ans = -1;
        dp(1, 0);
        cout << ans << "\n";
    }
    return 0;
}