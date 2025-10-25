#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (char c : s) ans += (c - '0');
    cout << ans << "\n";
}