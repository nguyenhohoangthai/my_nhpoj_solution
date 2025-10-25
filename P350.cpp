#include <bits/stdc++.h>
using namespace std;
map<string, int> f;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    while (n--) {
        string a, b; cin >> a >> b;
        ++f[a];
        if (f[a] > k) cout << "FAIL\n";
        else cout << "SUCCESS\n";
    }
}