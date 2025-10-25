#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define ord(a) (int)(a-48)
#define str(a) to_string(a)
#define chr(a) str(a)[0]
#define sz(a) (int)a.size()
#define pb push_back
#define pf push_front
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define ff first
#define ss second
#define pi pair <int, int>
#define pii pair <int, pi>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define ms(f, s) memset(f, s, sizeof(f));
#define fto(i, a, b) for (auto i = a; i <= b; ++i)
#define fdto(i, a, b) for (auto i = a; i >= b; --i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define FOR(it, a) for (auto it: a)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define open(a) freopen(a".inp", "r", stdin); freopen(a".out", "w", stdout);
using namespace std;

const int maxN = 1e6+5;
const int oo = 1e18;

int ans;
int a[10], b[10], c[10];

signed main() {
//    open("phuong");
    fastio;
    fto(i, 1, 3) cin >> a[i] >> b[i];
    fto(i, 1, 2)
        fto(j, i+1, 3) {
            int k = 6 - i - j;
            fto(r1, 0, 1)
                fto(r2, 0, 1)
                    fto(r3, 0, 1) {
                        if (r1 == 1) swap(a[i], b[i]);
                        if (r2 == 1) swap(a[j], b[j]);
                        if (r3 == 1) swap(a[k], b[k]);

                        if (b[i] == b[j] && b[j] == b[k] && a[i] + a[j] + a[k] == b[i]) ans = b[i];
                        if (b[i] == b[j] && a[i] + a[j] == a[k] && b[i] + b[k] == a[k]) ans = a[k];
                        if (r1 == 1) swap(a[i], b[i]);
                        if (r2 == 1) swap(a[j], b[j]);
                        if (r3 == 1) swap(a[k], b[k]);
                    }
        }
    cout << ans << endl;
    return 0;
}