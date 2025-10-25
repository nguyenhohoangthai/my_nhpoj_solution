#include <bits/stdc++.h>
#define oo 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ii pair <int, int>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int a[105][105], b[105][105], n, m, p;

int sigma(int start, int stop, int p_a, int p_b) {
    int res = 0;
    fto(k, start, stop) {
        res += a[p_a][k] * b[k][p_b];
    }
    return res;
}

void solve(){
    fto(i, 1, m) {
        fto(j, 1, p) cout << sigma(1, n, i, j) << " ";
        cout << "\n";
    }
}

int main(){
    fastio;
    cin >> m >> n >> p;
    fto(i, 1, m) {
        fto(j, 1, n) cin >> a[i][j];
    }
    fto(i, 1, n) {
        fto(j, 1, p) cin >> b[i][j];
    }
    solve();
}