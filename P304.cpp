#include <bits/stdc++.h>
using namespace std;
int n, a[100005], ans, res;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (a[n] & 1) a[n+1] = 1;
    else a[n+1] = 2;
    res = 1;
    for (int i = 2; i <= n+1; ++i) {
        if (a[i] % 2 == a[i-1] % 2) {
            ans = max(ans, res);
            res = 1;
        }else ++res;
    }
    cout << ans;
}