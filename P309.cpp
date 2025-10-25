#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define int long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fllto(i, a, b) for (long long i = a; i <= b; ++i)
#define flldto(i, a, b) for (long long i = a; i >= b; --i)
#define fvt(i, g) for (int i : g)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text 3\Packages\User
map<int, int> mpa;
int a[100005];
void ptts(int a) {
    if (a == 1) {
        ++mpa[a];
        return;
    }
    for (int i = 2; i * i <= a; ++i) {
        while (a % i == 0) {
            mpa[i] += 1;
            a /= i;
        }
    }
    if (a > 1) mpa[a] += 1;
}
int lt(int a, int b, int m) {
    if (b == 0) return 1;
    if (b & 1) return (a * lt(a, b-1, m) % m) % m;
    int tmp = lt(a, b/2, m) % m;
    return (tmp * tmp) % m;
}
main(){
    fastio;
    int m, n, k; cin >> m >> n >> k;
    int mx_val = 0;
    fto(i, 1, m) {
        cin >> a[i];
        mx_val = max(mx_val, a[i]);
        ptts(a[i]);
    }
    fto(i, 1, n) {
        int x; cin >> x;
        if (x == 1) --mpa[1];
        else{
            for (int i = 2; i * i <= x; ++i) {
                while (x % i == 0) {
                    mpa[i] -= 1;
                    x /= i;
                }
            }
            if (x > 1) mpa[x] -= 1;
        }
    }
    int ans = 1;
    fto(i, 1, mx_val) {
        if (mpa[i] > 0) ans = (ans * lt(i, mpa[i], k) % k) % k;
    }
    cout << ans;
}