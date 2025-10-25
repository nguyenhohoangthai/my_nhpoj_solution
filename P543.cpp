/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
#define ff first
#define ss second
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define pii pair<int, int>
#define pq priority_queue<pii, vector<pii>, greater<pii>>
#define int long long
#define db double
#define sz(a) (int) a.size()
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define yes "YES"
#define no "NO"
#define PI acos(-1)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct matrix {
int cell[2][2];
    matrix() {
        mem(cell, 0);
    }
};
int n;
matrix nhanmt(matrix a, matrix b) {
    matrix c;
    fto(i, 0, 1) {
        fto(j, 0, 1) {
            fto(k, 0, 1) c.cell[i][j] = (c.cell[i][j] + (a.cell[i][k] * b.cell[k][j]) % oo) % oo;
        }
    }
    return c;
}
matrix lt(matrix A, int b) {
    if (b == 1) return A;
    if (b & 1) return nhanmt(A, lt(A, b-1));
    matrix t = lt(A, b >> 1);
    return nhanmt(t, t);
}
signed main() {
    fastio;
    #define test "P543"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    if (n == 1) cout << 2 << "\n";
    else if (n == 2) cout << 4 << "\n";
    else {
        matrix base;
        base.cell[0][0] = 0; base.cell[0][1] = 1;
        base.cell[1][0] = 1; base.cell[1][1] = 1;
        base = lt(base, n-2);
        cout << (2 * base.cell[1][0] + 4 * base.cell[1][1]) % oo << "\n";
    }
    return 0;
}