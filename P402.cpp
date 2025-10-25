#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    cout << ((a / 2) + (a & 1) + (b / 2) + (b & 1) + (c / 2) + (c & 1)) << "\n";
}