#include <bits/stdc++.h>
using namespace std;
int freq[1001];
int main() {
    int n; cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; ++i) cin >> a[i], ++freq[a[i]];
    for (int i = 1; i <= n; ++i) {
        if (freq[a[i]] == 1) {
            cout << a[i] << "\n";
            return 0;
        }
    }
}