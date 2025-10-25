#include <bits/stdc++.h>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
int n, m, q, ans, f[1000005];
long long v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    scanf("%d%d", &m, &n);
    scanf("%d", &q);
    if (m <= 1005 && n <= 1005) {
        fto(i, 1, m) {
            fto(j, 1, n) f[i*j] += 1;
        }
        while (q--) {
            scanf("%lld", &v);
            cout << f[v] << "\n";
        }
    }
    else{
        while (q--) {
            ans = 0;
            scanf("%lld", &v);
            for (int i = 1; i <= sqrt(v); ++i) {
                if (v % i == 0) {
                    long long x = v / i;
                    int y = i;
                    if (x <= m && y <= n) ++ans;
                    if (v / i == i) break;
                    if (x <= n && y <= m) ++ans;
                }
            }
            printf("%lld\n", ans);
        }
    }
}