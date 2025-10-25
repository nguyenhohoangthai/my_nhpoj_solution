#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define cell(A, i, j) A.cell[i][j]
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fllto(i, a, b) for (long long i = a; i <= b; ++i)
#define flldto(i, a, b) for (long long i = a; i >= b; --i)
#define fvt(i, g) for (auto i : g)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100000;
long long a, b, m, n, ans, prv;

struct matrix {
long long cell[5][5];
};

long long nhan(long long x, long long y) {
	if (y == 0) return 0;
	if (y & 1) return (x % m + nhan(x, y-1) % m) % m;
	long long res = nhan(x, y/2) % m;
	return (res + res) % m;
}

matrix nhanmt(matrix A, matrix B) {
	matrix C;
	fto(i, 1, 3) {
		fto(j, 1, 3) {
			cell(C, i, j) = 0;
			fto(k, 1, 3) cell(C, i, j) = (cell(C, i, j) % m + nhan(cell(A, i, k), cell(B, k, j)) % m) % m;
		}
	}
	return C;
}

matrix lt(matrix A, long long x) {
	if (x == 1) return A;
	if (x & 1) return nhanmt(A, lt(A, x-1));
	matrix I = lt(A, x/2);
	return nhanmt(I, I);
}



int main() {
    fastio;
    cin >> a >> b >> m >> n;
    ans = 0;
    if (n <= maxN) {
    	if (a <= maxN && b <= maxN && m <= maxN) {
	    	prv = b;
	    	fto(i, 1, n-2) {
	    		ans = (a % m + (b * prv) % m) % m;
	    		prv = ans;
	    	}
	    	cout << ans << "\n";
	    }
	    else {
	    	prv = b;
	    	fto(i, 1, n-2) {
	    		ans = (a % m + nhan(b, prv) % m) % m;
	    		prv = ans;
	    	}
	    	cout << ans << "\n";
	    }
    }
    else {
    	matrix A;
    	cell(A, 1, 1) = 1; cell(A, 1, 2) = cell(A, 1, 3) = 0;
    	cell(A, 2, 1) = cell(A, 2, 3) = 0; cell(A, 2, 2) = 1;
    	cell(A, 3, 1) = 1; cell(A, 3, 2) = 0; cell(A, 3, 3) = b;
    	A = lt(A, n-3);
    	matrix I;
    	cell(I, 1, 1) = a;
    	cell(I, 2, 1) = b;
    	cell(I, 3, 1) = (a % m + nhan(b, b) % m) % m;
    	ans = (nhan(cell(A, 3, 1), cell(I, 1, 1)) % m) % m;
    	ans = (ans + nhan(cell(A, 3, 3), cell(I, 3, 1) % m)) % m;
    	cout << ans % m;
    }
    return 0;
}