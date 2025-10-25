#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p, e, i, d, x, y, z, k;
int main() {
    cin >> p >> e >> i >> d;
    while (1) {
        k = p + 23*x;
        if (k > d && (k-e) % 28 == 0 && (k-i) % 33 == 0) {
            cout << k - d << "\n";
            return 0;
        }
        ++x;
    }
}