#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    for (int i = 0; i < (int) s.size(); ++i) {
        for (int j = 1; j <= i+1; ++j) cout << s[i];
    }
    cout << "\n";
}