#include <bits/stdc++.h>
using namespace std;
int h, m, s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> h >> m >> s;
    cout << (h * 3600 + m * 60 + s) << "\n";
}