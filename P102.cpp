/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fat(i, a) for (auto i : a)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, visited[1005];
pair<double, double> a[1005];
double low, high, mid, ans;
double bp(double x) {
    return x * x;
}
double dis(int i, int j) {
    double x_1 = a[i].ff;
    double y_1 = a[i].ss;
    double x_2 = a[j].ff;
    double y_2 = a[j].ss;
    return sqrt(bp(x_1 - x_2) + bp(y_1 - y_2)) * 1.0;
}
int check(double x) {
    memset(visited, 0, sizeof visited);
    fto(i, 1, n) {
        fto(j, 1, n) {
            if (i != j && dis(i, j) <= 2*x) visited[j] = 1;
        }
    }
    fto(i, 1, n) {
        if (visited[i] == 0) return 0;
    }
    return 1;
}
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i].ff >> a[i].ss;
    low = 0.00000000;
    high = 1000000007.00000000;
    while (low <= high) {
        mid = (low + high) / (2 * 1.0);
        if (check(mid) == 1) {
            high = mid - 0.00000001;
            ans = mid;
        } else low = mid + 0.00000001;
    }
    cout << fixed << setprecision(7) << ans << "\n";
    return 0;
}