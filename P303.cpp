#include <bits/stdc++.h>
using namespace std;
int n, a[1005], dd[1005];
set<int> t;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        t.insert(a[i]);
        ++dd[a[i]];
    }
    for (auto temp : t) {
        if (dd[temp] == 1) {
            cout << temp;
            break;
        }
    }
}