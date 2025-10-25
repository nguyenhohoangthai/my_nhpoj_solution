#include <bits/stdc++.h>
#define oo 998244353
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
    fto(i, 0, 2) {
        vector <long long> t;
        fto(j, 0, 2) {
            long long tmp = 0;
            fto(k, 0, 2) tmp = (tmp + a[i][k] * b[k][j] % oo) % oo;
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
    long long k; cin >> k;
    vii a;
    a.pb({1, 1});
    a.pb({1, 0});
    vii f = ltmt(k+1, a);
    cout << f[0][1] * f[0][0] % oo;
}