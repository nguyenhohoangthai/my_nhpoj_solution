#include<bits/stdc++.h>
using namespace std;
int n;
bool found;
int main() {
    cin >> n;
    string s; getline(cin, s);
    for (int test = 1; test <= n; ++test) {
        string tmp;
        getline(cin, tmp);
        string s;
        int last_char_pos = -1;
        for (int i = tmp.size() - 1; i >= 0; --i) {
            if (tmp[i] != ' ') {
                for (int j = 0; j <= i; ++j) s += tmp[j];
                break;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0) {
                if ('A' <= s[i] && s[i] <= 'Z') continue;
                cout << test << " ";
                found = true;
                break;
            }
            else {
                if ('a' <= s[i] && s[i] <= 'z') continue;
                cout << test << " ";
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << 0 << "\n";
    }

    return 0;
}