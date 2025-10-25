#include <bits/stdc++.h>
#define oo 1000000007
using namespace std;
long long n, f[100005];
int main(){
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; ++i) f[i] = (f[i-1] + f[i-2]) % (int) oo;
    cout << f[n] % (long long) oo;
}