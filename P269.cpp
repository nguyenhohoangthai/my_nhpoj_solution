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
long long n;
long long check(long long n) {
    if (n == 2 || n == 3) return 1LL;
    if (n == 1 || n % 2 == 0) return 0LL;
    for (long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0LL;
    }
    return 1LL;
}
int main() {
    fastio;
    cin >> n;
    if (n == 1) cout << 2;
    else if (n == 2) cout << 3;
    else {
        ++n;
        while (true) {
            if (check(n)) {
                cout << n;
                break;
            }
            ++n;
        }
    }
    return 0;
}