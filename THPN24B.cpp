/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 1000005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, q, a[maxN], p[maxN], f[maxN], cnt[maxN];
vector<pair<int, int>> place;
int main() {
    fastio;
    cin >> n >> q;
    fto(i, 1, n) {
        cin >> a[i];
        f[a[i]] += 1;
    }
    fto(i, 1, q) cin >> p[i];
    cnt[1] = n;
    fto(i, 2, 1000000) {
        for (int j = i * 1; j <= 1000000; j += i) {
            if (f[j]) cnt[i] += f[j];
        }
    }
    place.pb({1, cnt[1]});
    fto(i, 2, maxN - 4) {
        if (cnt[i] > 0) {
            place.pb({i, cnt[i] + place[sz(place) - 1].ss});
        }
    }
    fto(i, 1, q) {
        int low = 0;
        int high = sz(place) - 1;
        int tmp = 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (place[mid].ss >= p[i]) {
                tmp = place[mid].ff;
                high = mid - 1;
            } else low = mid + 1;
        }
        cout << tmp << " ";
    }
    cout << "\n";
    return 0;
}