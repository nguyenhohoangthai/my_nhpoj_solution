#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            sum += x;
        }
        cout << ((sum & 1) ? "First" : "Second") << "\n";
    }
}