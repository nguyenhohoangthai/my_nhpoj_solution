#include <bits/stdc++.h>
using namespace std;
int n, a[100005], f[100005];
int dp(int x){
    if (x == 1) return 0;
    if (x == 2) return abs(a[2] - a[1]);
    if (f[x] > 0) return f[x];
    f[x] = min(dp(x-1) + abs(a[x] - a[x-1]), dp(x-2) + abs(a[x] - a[x-2]));
    return f[x];
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << dp(n);
    return 0;
}