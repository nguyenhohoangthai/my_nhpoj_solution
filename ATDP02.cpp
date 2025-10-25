#include <bits/stdc++.h>
using namespace std;
int n, a[100005], f[100005], k;
int dp(int x){
    if (x == 1) return 0;
    if (x == 2) return abs(a[2] - a[1]);
    int first = 1000000001;
    for (int i = 1; i <= min(k, x); ++i){
        int temp = 0;
        if (f[x-i] > 0) temp = f[x-i];
        else{
            temp = dp(x-i);
            f[x-i] = temp;
        }
        first = min(first, temp + abs(a[x] - a[x-i]));
    }
    return first;
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << dp(n);
    return 0;
}