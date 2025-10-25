#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, x, y, k;

int main(){
    cin >> a >> b >> c >> d >> k;
    if (d - (b+d) %k >= c) cout << b << " " << d - (b+d) %k;
    else if( b - (b+c) %k >= a){
        cout << b - (b+c) % k << " " << c;
    }else cout << -1;
}