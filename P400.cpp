#include <bits/stdc++.h>
using namespace std;
double b, c;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> b >> c;
    cout << fixed << setprecision(1) << b * c / 2 << "\n" << sqrt(b*b + c*c) << "\n";
}