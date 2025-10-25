/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, a[maxN];
multiset<int, greater<int>> Q;
void solve() {
    int cnt = n;
    fto(i, 1, n) {
        Q.insert(a[i]);
        while (sz(Q) && *Q.begin() == cnt) {
            --cnt;
            cout << *Q.begin() << " ";
            Q.erase(Q.begin());
        }
        cout << "\n";
    }
}

void input() {
    cin >> n;
    fto(i, 1, n) cin >> a[i];
}

int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    input();
    solve();
    return 0;
}