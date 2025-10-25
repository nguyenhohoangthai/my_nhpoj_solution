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
int row, col;
    vector<vector<int>> cell;

    matrix() {}
    matrix(int n, int m) {
        row = n;
        col = m;
        cell.resize(n, vector<int>(m, 0));
    }
    matrix(vector<vector<int>> board) {
        cell = board;
        row = sz(cell);
        col = sz(cell[0]);
    }
};

matrix nhan(matrix A, matrix B) {
    matrix C(A.row, B.col);
    fto(i, 0, A.row - 1) {
        fto(j, 0, B.col - 1) {
            fto(k, 0, A.col - 1) {
                C.cell[i][j] = (C.cell[i][j] + (A.cell[i][k] * B.cell[k][j]) % oo + oo*oo) % oo;
            }
        }
    }
    return C;
}


matrix lt(matrix A, int b) {
    if (b == 1) return A;
    if (b & 1) return nhan(A, lt(A, b-1));
    matrix t = lt(A, b >> 1);
    return nhan(t, t);
}


int n, dp[20][2], ans;
signed main() {
    fastio;
    #define test "NCK012"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    matrix base({{19, 6, 0, 0},
                {-19, -6, 26, 0},
                {0, 0, 26, 0},
                {19, 6, 0, 1}}
    );
    matrix hs({{1}, {0}, {1}, {0}});

    base = lt(base, n);
    hs = nhan(base, hs);

    cout << hs.cell[3][0] << "\n";
    return 0;
}