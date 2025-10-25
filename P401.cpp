#include <bits/stdc++.h>
using namespace std;
int b, c;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> b >> c;
    cout << c / b << "\n" << (c - (c / b) * b) << "\n";
}