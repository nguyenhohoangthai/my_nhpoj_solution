/*Hoang Thai*/
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
int cell[7][7];
    matrix() {
        mem(cell, 0);
    }
};

int n;
matrix base, hs;
matrix nhanmt(matrix a, matrix b) {
    matrix c;
    fto(i, 0, 6) {
        fto(j, 0, 6) {
            fto(k, 0, 6) {
                c.cell[i][j] = (c.cell[i][j] + (a.cell[i][k] * b.cell[k][j] + oo) % oo) % oo;
            }
        }
    }
    return c;
}
matrix lt(matrix A, int b) {
    if (b == 1) return A;
    if (b & 1) return nhanmt(A, lt(A, b-1));
    matrix t = lt(A, b / 2);
    return nhanmt(t, t);
}

signed main() {
    fastio;
    #define test "P544"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    hs.cell[0][0] = 1;
    hs.cell[1][0] = 2;
    hs.cell[2][0] = 3;
    hs.cell[3][0] = 6;
    hs.cell[4][0] = 8;
    hs.cell[5][0] = 12;
    if (n <= 6) cout << hs.cell[n-1][0] << "\n";
    else {
        base.cell[0][0] = 0; base.cell[0][1] = 1; base.cell[0][2] = 0; base.cell[0][3] = 0; base.cell[0][4] = 0; base.cell[0][5] = 0;
        base.cell[1][0] = 0; base.cell[1][1] = 0; base.cell[1][2] = 1; base.cell[1][3] = 0; base.cell[1][4] = 0; base.cell[1][5] = 0;
        base.cell[2][0] = 0; base.cell[2][1] = 0; base.cell[2][2] = 0; base.cell[2][3] = 1; base.cell[2][4] = 0; base.cell[2][5] = 0;
        base.cell[3][0] = 0; base.cell[3][1] = 0; base.cell[3][2] = 0; base.cell[3][3] = 0; base.cell[3][4] = 1; base.cell[3][5] = 0;
        base.cell[4][0] = 0; base.cell[4][1] = 0; base.cell[4][2] = 0; base.cell[4][3] = 0; base.cell[4][4] = 0; base.cell[4][5] = 1;
        base.cell[5][0] = -1; base.cell[5][1] = -1; base.cell[5][2] = 2; base.cell[5][3] = 1; base.cell[5][4] = 0; base.cell[5][5] = 1;
        base = lt(base, n - 6);
        hs = nhanmt(base, hs);
        cout << hs.cell[5][0] << "\n";
    }
    return 0;
}