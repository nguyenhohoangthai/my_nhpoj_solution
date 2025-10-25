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
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fllto(i, a, b) for (long long i = a; i <= b; ++i)
#define flldto(i, a, b) for (long long i = a; i >= b; --i)
#define fvt(i, g) for (int i : g)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define open(a) freopen(a".inp", "r", stdin); freopen(a".out", "w", stdout);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text 3\Packages\User
int n, t[100005], ans;
int main(){
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> t[i];
    if (n <= 3000) {
        sort(t+1, t+n+1);
        fto(a, 1, n-1) {
            fto(b, 1, n) {
                if (a != b) {
                    int low = 1;
                    int high = n;
                    int pos = 0;
                    while (low <= high) {
                        int mid = (low + high) / 2;
                        if (t[mid] <= t[b] - t[a]) {
                            pos = mid;
                            low = mid + 1;
                        } else high = mid - 1;
                    }
                    if (t[pos] == t[b] - t[a] && pos != a && pos != b) ++ans;
                }
            }
        }
        cout << ans;
    }
    else {
        long long res = 0;
        fto(i, 1, n) res += (i-1) / 2 * 2;
        cout << res;
    }
    return 0;
}