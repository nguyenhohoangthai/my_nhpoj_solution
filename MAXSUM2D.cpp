#include <bits/stdc++.h>
using namespace std;
int m, n, a[505][505], f[505][505], t[505], mx, ts, s_1, s_2, ans;

int main(){
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            f[i][j] = f[i][j-1] + a[i][j];
        }

    }
    mx = 0;
    ts = 0;
    s_1 = 0;
    s_2 = 0;
    for (int l = 1; l <= n; ++l){
        for (int r = l; r <= n; ++r){
            s_1 = 0;
            s_2 = 0;
            for (int i = 1; i <= m; ++i) t[i] = f[i][r] - f[i][l-1];
            for (int i = 1; i <= m; ++i){
                s_1 += t[i];
                s_2 = max(s_2, s_1);
                s_1 = max(s_1, 0);
            }
            mx = max(mx, s_2);
        }
    }
    cout << mx << "\n";
}