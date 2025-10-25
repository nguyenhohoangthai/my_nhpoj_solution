#include <bits/stdc++.h>
using namespace std;
int T, n, ans;
string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> s;
        n = ((int) s.size());
        ans = 9 * (n - 1);
        for (int i = 1; i <= 9; ++i) {
            string tmp = "";
            for (int j = 1; j <= n; ++j) tmp += (i + '0');
            ans += (tmp <= s);
        }
        cout << ans << "\n";
    }
}