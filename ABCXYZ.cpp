#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, mx;
long long x, y;

int main(){
    cin >> n;
    cin >> a >> b >> c;
    mx = min(1000, n);
    for (long long z = -mx; z <= mx; ++z){
        if (z != 0){
            x = ((a-z) + sqrt((a-z)*(a-z) - 4*(b/z))) / 2;
            y = ((a-z) - sqrt((a-z)*(a-z) - 4*(b/z))) / 2;
            if ((x + y + z == a) && (x * y * z == b) && (x*x + y*y + z*z) == c){
                cout << z << " " << y << " " << x << "\n";
                break;
            }
        }
        else{
            for (y = -mx; y <= mx + 1; ++y){
                x = a - y - z;
                if ((x + y + z == a) && (x * y * z == b) && (x*x + y*y + z*z) == c){
                    cout << z << " " << y << " " << x << "\n";
                    break;
                }
            }
        }
    }
}