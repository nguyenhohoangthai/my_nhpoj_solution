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
long long m, n, a[105], f[300005];

int main(){
    fastio;
    cin >> n >> m;
    fto(i, 1, m) {
        cin >> a[i];
        f[a[i]] = 1;
    }
    fto(i, 2, n) {
        if (f[i] == 0) {
            fto(j, 1, m) {
                if (i - a[j] >= 0) {
                    if (f[i - a[j]] == 0) {
                        f[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    fto(i, 1, n) cout << f[i] << "\n";
}