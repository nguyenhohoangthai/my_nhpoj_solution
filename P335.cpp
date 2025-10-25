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
const long long oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
long long n, a, b;
long long lt(long long a, long long b) {
    if (b == 0) return 1LL;
    if (b & 1) return (a * lt(a, b-1) % oo) % oo;
    long long t = lt(a, b/2) % oo;
    return (t * t) % oo;
}
int main() {
    fastio;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << lt(a, b) << "\n";
    }
    return 0;
}