#include <bits/stdc++.h>
using namespace std;
int n, x, q, f[1000005];
int main(){
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> q;
        f[q] += 1;
    }
    while (x--){
        cin >> q;
        if (f[q] > 0) cout << 1;
        else cout << 0;
        cout << "\n";
    }
}