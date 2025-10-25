#include <bits/stdc++.h>
#define oo 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ii pair <int, int>
#define vii vector<vector<long long>>
#define fto(i, a, b) for (int i = a; i < b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
long long len;
vii nhanmt(vii a, vii b) {
    vii res;
    fto(i, 0, len) {
        vector <long long> t;
        fto(j, 0, len) {
            long long tmp = 0;
            fto(k, 0, len) tmp = (tmp + a[i][k] * b[k][j] % oo) % oo;
            t.pb(tmp);
        }
        res.pb(t);
    }
    return res;
}

vii ltmt(long long t, vii a) {
    if (t == 1) return a;
    if (t & 1) return nhanmt(a, ltmt(t-1, a));
    vii tmp = ltmt(t/2, a);
    return nhanmt(tmp, tmp);
}

int main(){
    fastio;
    int n, k; cin >> n >> k;
    vii a;
    fto(i, 0, n) {
        vector<long long> inp;
        fto(j, 0, n) {
            int x; cin >> x;
            inp.pb(x);
        }
        a.pb(inp);
    }
    len = n;
    vii f = ltmt(k, a);
    for (auto t : f) {
        for (auto tmp : t) cout << tmp << " ";
        cout << "\n";
    }
}