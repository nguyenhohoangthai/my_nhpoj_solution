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
int n, a[100005], ans, res, cmp;

int main(){
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    a[n+1] = oo;
    cmp = a[1];
    ans = 1;
    res = 1;
    fto(i, 2, n+1) {
        if (a[i] != cmp) {
            cmp = a[i];
            ans = max(ans, res);
            res = 1;
        } else ++res;
    }
    cout << ans;
}