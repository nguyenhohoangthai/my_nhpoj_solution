/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fat(i, a) for (auto i : a)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n;
string s;
int num(char x) {
    return x - '0';
}
int main() {
    fastio;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s[1] == '*') {
            if (s[3] == '*') cout << num(s[0]) * num(s[2]) * num(s[4]);
            else cout << num(s[0]) * num(s[2]) + num(s[4]);
        }
        else {
            if (s[3] == '*') cout << num(s[0]) + num(s[2]) * num(s[4]);
            else cout << num(s[0]) + num(s[2]) + num(s[4]);
        }
        cout << "\n";
    }
    return 0;
}