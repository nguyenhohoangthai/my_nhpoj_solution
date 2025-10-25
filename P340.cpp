/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define sz(a) a.size()
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string s, inp;
int n;
map<string, int> ch;
map<pair<int, string>, int> f;
int dp(int i, string t) {
    if (i == sz(s)) return ch[t];
    if (f[{i, t}]) return f[{i, t}];
    int res = dp(i+1, t + s[i]);
    string tmp = "";
    tmp += s[i];
    if (ch[t]) res += dp(i+1, tmp);
    return f[{i, t}] = res;
}
int main() {
    fastio;
    cin >> s;
    cin >> n;
    fto(i, 1, n) {
        cin >> inp;
        ch[inp] = 1;
    }
    cout << dp(0, "") << "\n";
    return 0;
}