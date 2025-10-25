#include <bits/stdc++.h>
using namespace std;
int n, x;
int get(int x) {
    int res = 0;
    for (int i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            ++res;
            if (x / i == i) break;
            ++res;
        }
    }
    return res;
}
int main() {
    cin >> n;
    while (n--) {
        cin >> x;
        cout << get(x) << "\n";
    }
}