#include <bits/stdc++.h>
using namespace std;
int n, x, f[105], t;
int main() {
    cin >> n;
    t = -105;
    while (n--) {
        cin >> x;
        t = max(t, x);
        f[x] += 1;
    }
    cout << f[t];
}