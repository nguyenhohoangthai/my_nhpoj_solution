#include<bits/stdc++.h>
using namespace std;
int n, h, x, ans;
int main() {
    cin >> n >> h;
    while (n--) {
        cin >> x;
        ans += (x <= h);
    }
    cout << ans << "\n";
}