#include <bits/stdc++.h>
using namespace std;
long long n, k, a[100005], f[100005], ans, low, high, mid;
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) f[i] = f[i-1] + a[i];
    ans = 0;
    for (int i = 1; i <= n; ++i){
        low = i;
        high = n;
        while (low <= high){
            mid = (low + high) / 2;
            if (f[mid] - f[i-1] <= k){
                ans = max(ans, f[mid] - f[i-1]);
                low = mid + 1;
            }else high = mid - 1;
        }
    }
    cout << ans << "\n";
}