/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define mp make_pair
#define sz(a) a.size()
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
long long a, b, f[20][155][5], n, x, t, r;
string c;
long long dp(int i, int s, int t) {
    if (i == n) return s == x;
    if (f[i][s][t] != -1) return f[i][s][t];
    int limit = 0;
    if (t == 1) limit = c[i] - '0';
    else limit = 9;
    long long res = 0;
    fto(d, 0, limit) {
        if (d == limit && t == 1) res += dp(i + 1, s + d, 1);
        else res += dp(i + 1, s + d, 0);
    }
    return f[i][s][t] = res;
}
long long g(long long x) {
    memset(f, -1, sizeof f);
    c = to_string(x);
    n = c.size();
    return dp(0, 0, 1);
}
long long get_sum(long long x) {
    long long res = 0LL;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}
long long check(string p) {
    long long res = 0;
    fto(i, 0, sz(p) - 1) res += (p[i] - '0');
    if (res == x) return 1LL;
    return 0LL;
}
long long t_int(char t) {
    return t - '0';
}
long long t_char(long long t) {
    return t + '0';
}
int main() {
    fastio;
    cin >> a >> b >> x;
    cout << g(b) - g(a-1) << "\n";
    t = get_sum(a);
    if (t == x) cout << a << "\n";
    else if (t < x) {
        r = x - t;
        string cmp = to_string(a);
        fto(i, 1, 20) cmp = "0" + cmp;
        fdto(i, sz(cmp) - 1, 0) {
            long long c_plus = 9 - t_int(cmp[i]);
            if (c_plus >= r) {
                cmp[i] = t_char((t_int(cmp[i]) + r));
                break;
            }
            else {
                cmp[i] = '9';
                r -= c_plus;
            }
        }
        if (check(cmp) == 0) {
            long long addin = 0;
            fto(i, 0, sz(cmp) - 1) addin += t_int(cmp[i]);
            cmp = to_string(x - addin);
        }
        int p = 0;
        fto(i, 0, sz(cmp) - 1) {
            if (cmp[i] != '0') {
                p = i;
                break;
            }
        }
        fto(i, p, sz(cmp) - 1) cout << cmp[i];
    }
    else {
        r = t - x;
        string cmp = to_string(a);
        fdto(i, sz(cmp) - 1, 0) {
            if (t_int(cmp[i]) > r) {
                cmp[i-1] = t_char(t_int(cmp[i-1]) + 1);
                cmp[i] = '0';
            }
            else {
                cmp[i-1] = t_char(t_int(cmp[i-1]) + 1);;
                r -= t_int(cmp[i]);
                cmp[i] = '0';
            }
        }
        cout << cmp << "\n";
    }
    return 0;
}