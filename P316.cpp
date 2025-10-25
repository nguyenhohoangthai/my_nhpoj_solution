#include <bits/stdc++.h>
using namespace std;
long long mx, n, cnt, prv, i;
int main() {
    mx = 1e18;
    while (cin >> n) {
        if (cnt > 0) {
            if (n - prv <= mx) {
                i = cnt;
                mx = n-prv;
            }
        }
        prv = n;
        ++cnt;
    }
    cout << i<< "\n";
}