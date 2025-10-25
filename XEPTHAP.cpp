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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
long long n, m;
long long nhan(long long a, long long b) {
   	if (b == 0) return 0LL;
    if (b % 2) return (a + nhan(a, b-1)) % m;
    long long tmp = nhan(a, b/2);
    return (tmp + tmp) % m;
}
struct matrix {	ll cell[10][10];
};

matrix nhanmt(matrix A, matrix B) {
    matrix C;
    fto(i, 1, 4) {
        fto(j, 1, 4) {
            cell(C, i, j) = 0LL;
            fto(k, 1, 4) {
            	ll tmp_1 = (long long) cell(A, i, k);
            	ll tmp_2 = (long long) cell(B, k, j);
            	int dau_1 = 0;
            	int dau_2 = 0;
            	if (tmp_1 < 0) dau_1 = 1;
            	if (tmp_2 < 0) dau_2 = 2;
            	tmp_1 = abs(tmp_1); tmp_2 = abs(tmp_2);
            	tmp_1 = nhan(tmp_1, tmp_2);
            	if (dau_1 != dau_2) tmp_1 *= (-1);
            	cell(C, i, j) = (tmp_1 + cell(C, i, j) + m) % m;
            }
        }
    }
    return C;
}
matrix lt(matrix A, ll x) {
    if (x == 1) return A;
    if (x & 1) return nhanmt(A, lt(A, x-1));
    matrix T = lt(A, x / 2);
    return nhanmt(T, T);
}

int main() {
    fastio;
    cin >> n >> m;
    if (n == 1) cout << 1;
    else if (n == 2) cout << 5;
    else {
	    matrix A;
	    cell(A, 1, 1) = 0; cell(A, 1, 2) = 1; cell(A, 1, 3) = 0; cell(A, 1, 4) = 0;
	    cell(A, 2, 1) = -1; cell(A, 2, 2) = 2; cell(A, 2, 3) = 1; cell(A, 2, 4) = 0;
	    cell(A, 3, 1) = 0; cell(A, 3, 2) = 0; cell(A, 3, 3) = 1; cell(A, 3, 4) = 1;
	    cell(A, 4, 1) = 0; cell(A, 4, 2) = 0; cell(A, 4, 3) = 0; cell(A, 4, 4) = 1;
	    A = lt(A, n-2);
	    matrix I;
	    cell(I, 1, 1) = 1;
	    cell(I, 2, 1) = 5;
	    cell(I, 3, 1) = 5;
	    cell(I, 4, 1) = 2;
	    I = nhanmt(A, I);
	    cout << cell(I, 2, 1)<< "\n";
	}
    return 0;
}