#include <bits/stdc++.h>
using namespace std;
int T, n, ans;
int check(int x) {
    if (x == 2 || x == 3 || x == 5) return 1;
    if (x == 1 || x % 2 == 0 || x % 3 == 0 || x % 5 == 0) return 0;
    for (int i = 5; i <= sqrt(x); i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}
int main() {
    cin >> T;
    while (T--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        ans += check(stoi(s));
    }
    cout << ans << "\n";
}