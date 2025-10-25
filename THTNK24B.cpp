#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        if (t == 1) a += b;
        else b += a;
    }
    cout << a << " " << b << "\n";
}