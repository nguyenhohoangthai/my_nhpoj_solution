/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define sz(a) a.size()
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int maxN = 1000000;
int m, n, x, y, check_nu[1000000];
vector<int> nam;
int main() {
    fastio;
    cin >> m >> x;
    fto(i, 1, x) {
        int t; cin >> t;
        check_nu[t] = 1;
    }
    cin >> n >> y;
    fto(i, 1, y) {
        int t; cin >> t;
        nam.pb(t);
    }
    int cnt_nam = 0;
    fto(i, 1, m) {
        if (check_nu[i] == 0 && cnt_nam < sz(nam)) {
            cout << 7 << " " << nam[cnt_nam++] << " " << i << "\n";
            cout << 2 << " " << i << "\n";
        }
        else if (check_nu[i] == 1)  cout << 2 << " " << i << "\n";
    }
    // fto(i, cnt_nam, sz(nam) - 1) {
//     cout << 1 << " " << nam[i] << "\n";
//     cout << 3 << " " << nam[i] << "\n";
// }
cout << 0;
    return 0;
}