#include <bits/stdc++.h>
using namespace std;
int n, s, a[100005], l, r, ans, f[100005];

int main(){
    cin >> n >> s;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    ans = n+5;
    l = 1;
    r = 1;
    while (r <= n){
        if (f[r] - f[l-1] <= s) ++r;
        else{
            ans = min(ans, r - l + 1);
            ++l;
        }
    }
    if (ans == n+5) cout << -1 << "\n";
    else cout << ans << "\n";
}