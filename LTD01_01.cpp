#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, a[2005], s, pos_up, pos_down, ans, temp, mn, mx;

int main(){
    cin >> n >> m >> x >> y;
    ans = 0;
    for (long long i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    if (x > m) {
        cout << 0 << "\n";
        return 0;
    }
    else{
        mn = x;
        mx = min(y, m);
        ans = 0;
        for (int i = 1; i <= n-2; ++i) {
            for (int j = i + 1; j <= n-1; ++j) {
                temp = a[i] + a[j];
                if (temp <= mx) {
                    if (temp < mn) pos_down = lower_bound(a+j+1, a+n+1, mn - temp) - a;
                    else pos_down = j+1;
                    pos_up = upper_bound(a+j+1, a+n+1, mx - temp) - a;
                    ans += (pos_up - pos_down);
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
}