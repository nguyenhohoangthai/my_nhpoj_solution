#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main() {
    fastio;
    int n; cin >> n;
    int ans = 0;
    while (n) {
        ans += ((n % 10) & 1 ? (n % 10) : 0);
        n /= 10;
    }
    cout << ans << "\n";
}