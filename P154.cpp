#include <bits/stdc++.h>
using namespace std;
int m, n, s, a[505][505], f[505][505], t[505], top, b, ans, t_2[505], cmp;

int main(){
    cin >> m >> n >> s;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            f[i][j] = f[i][j-1] + a[i][j];
        }
    }
    ans = m * n + 5;
    for (int l = 1; l <= n; ++l){
        for (int r = l; r <= n; ++r){
            for (int i = 1; i <= m; ++i) t_2[i] = t_2[i-1] + f[i][r] - f[i][l-1];
            top = 1;
            b = 1;
            while (top <= b && b <= m){
                if (t_2[b] - t_2[top-1] <= s) ++b;
                else{
                    ans = min(ans, (b - top + 1) * (r - l + 1));
                    ++top;
                }
            }
        }
    }
    cout << ans << "\n";
}