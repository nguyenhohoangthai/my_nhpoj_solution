#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, k; cin >> a >> b >> k;
    long long ans = 0;
    for (int i = a; i <= b; ++i) {
        if (i % k == 0) ans += (long long) i;
    }
    cout << ans << "\n";
    return 0;
}