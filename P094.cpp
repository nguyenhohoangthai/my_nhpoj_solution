#include <bits/stdc++.h>
#define oo 1000000007
#define fto(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
int n, a[1005], f[1005];

int main(){
    cin >> n;
    fto(i, 1, n) {
    	cin >> a[i];
    }
    f[1] = 1;
    f[2] = 3;
    fto(i, 3, n){
        f[i] = (f[i-1] + f[i-2] + 2) % oo;
    }
    cout << f[n] % oo << "\n";
}