#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, x, y, p, t;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> d >> x >> y;
    p = (x*d - b*y) / (a*d - b*c);
    t = (x - a * p) / b;
    cout << p << " " << t << "\n";
}