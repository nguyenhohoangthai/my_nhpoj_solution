#include <bits/stdc++.h>
using namespace std;

int n, f[100001], a[100001], ans;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[a[i]] = 1;
    }
    sort(a + 1, a + n / 2 + 1, greater<int>());
    for (int i = 1; i <= 2 * n; ++i)
        if (!f[i])
            v.push_back(i);
    for (int i = 1; i <= n / 2; ++i) {
        if (v[v.size() - 1] > a[i]) {
            ans++;
            v.erase(v.begin() + (v.size() - 1));
        }
    }
    sort(a + n / 2 + 2, a + n + 1);
    // for (auto x : v)
//     cout << x << '\n';
for (int i = n / 2 + 1; i <= n; ++i) {
        int l = 0, r = v.size() - 1, j = -1;
        while (l <= r) {
            int m = l + r >> 1;
            if (v[m] < a[i]) {
                l = m + 1;
                j = m;
            }
            else {
                r = m - 1;
            }
        }
        if (j == -1) continue;
        v.erase(v.begin() + j);
        ans++;
    }
    cout << ans;
}