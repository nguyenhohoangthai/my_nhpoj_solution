#include <bits/stdc++.h>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define sz(a) a.size()
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxN = 100005;
const int oo = 1000000007;
int n, x, ans;
vector<pair<int, int>> a;
int cmp(pair<int, int> x, pair<int, int> y) {
    return x.ss < y.ss;
}
signed main() {
    fastio;
    cin >> n >> x;
    ans = 0;
    fto(i, 1, n) {
        int t1, t2; cin >> t1 >> t2;
        if (t1 <= t2) continue;
        else a.pb({t1, t2});
    }
    ans = x;
    if (a.size() > 0) {
        sort(a.begin(), a.end(), cmp);
        int take = a[0].ff;
        int give = a[0].ss;
        fto(i, 1, a.size() - 1) {
            int take_1 = a[i].ff;
            int give_1 = a[i].ss;
            if (give_1 < take) take = max(take, take_1);
            else {
                ans += (take - give) * 2;
                take = take_1;
                give = give_1;
            }
            //cout << take << " " << give << " " << ans << endl;
        }
        ans += (take - give) * 2;
    }
    cout << ans;
}