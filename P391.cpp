#include <bits/stdc++.h>
using namespace std;
int h, m, s, sum;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> sum;
    s = sum % 60;
    sum /= 60;
    m = sum % 60;
    sum /= 60;
    h = sum;
    cout << h << " " << m << " " << s << "\n";
}