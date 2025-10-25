#include <bits/stdc++.h>
using namespace std;
int n, x, f[105], s, inp;
int main(){
    cin >> n;
    int rep = 2;
    while (rep--){
        cin >> x;
        for (int i = 1; i <= x; ++i){
            cin >> inp;
            if (f[inp] == 0){
                ++f[inp];
                ++s;
            }
        }
    }
    if (s == n) printf("It is an easy game.");
    else printf("It is difficult for us.");
}