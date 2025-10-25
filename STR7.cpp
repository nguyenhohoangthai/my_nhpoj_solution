#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    vector<string> ans;
    while (cin >> s) ans.push_back(s);
    for (int i = 0; i < (int) ans.size() - 1; ++i) cout << ans[i] << " ";
    cout << ans.back();
}