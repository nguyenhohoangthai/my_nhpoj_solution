#include <bits/stdc++.h>
using namespace std;
long long n, a[20], ans, x, T;
long long _lcm(long long x, long long y) {
    return (x * y) / __gcd(x, y);
}

int main() {
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> n;
        cin >> ans;
        for (int i = 2; i <= n; ++i){
            cin >> x;
            ans = _lcm(ans, x);
        }
        cout << ans << "\n";
    }
    return 0;
}