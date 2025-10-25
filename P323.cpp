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
vector<int> a;
int main() {
    fastio;
    fto(i, 1, 3) {
        int x; cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end());
    if (a[1] - a[0] == a[2] - a[1]) cout << 2*a[2] - a[1] << "\n";
    else if ((a[1] - a[0]) * 2 == a[2] - a[1]) cout << 2*a[1] - a[0] << "\n";
    else if ((a[2] - a[1]) * 2 == a[0]) cout << 2*a[1] - a[2] << "\n";
    else cout << 2*a[1] - a[2] << "\n";
    return 0;
}