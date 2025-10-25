#include <bits/stdc++.h>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        int cnt_a = 0;
        int cnt_b = 0;
        int cnt_c = 0;
        for (char c : s) {
            if (c == 'a') cnt_a = 1;
            else if (c == 'b') cnt_b = 1;
            else cnt_c = 1;
        }
        if (cnt_a + cnt_b + cnt_c == 2) cout << "EVEN\n";
        else cout << "ODD\n";
    }
}