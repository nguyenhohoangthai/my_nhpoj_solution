#include <bits/stdc++.h>
using namespace std;
int n, a[100005], s, ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        s = max(0, s + a[i]);
        ans = max(ans, s);
    }
    cout << ans;
}