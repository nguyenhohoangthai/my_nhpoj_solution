#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, idx, mx;
int main() {
    cin >> n >> m;
    idx = -1;
    while (n--) {
        cin >> a >> b;
        if (b > mx && b <= m) {
            mx = b;
            idx = a;
        }
    }
    cout << idx << "\n";
}