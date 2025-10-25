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
int n, a[100005], ans;
vector <int> f;
int main(){
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    f.pb(a[1]);
    ans = 1;
    fto(i, 2, n) {
        if (a[i] >= f[f.size() - 1]) {
            ++ans;
            f.pb(a[i]);
        }
        else {
            int low = 0;
            int high = f.size() - 1;
            int res = f.size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (f[mid] > a[i]) {
                    res = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            f[res] = a[i];
        }
    }
    cout << ans;
}