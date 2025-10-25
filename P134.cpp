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
int n, a[1005], c, l, ans;

int main(){
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n) {
        l = 0;
        c = 0;
        fto(j, i, n) {
            if (a[j] & 1) ++l;
            else ++c;
            if (l == c) ans = max(ans, j-i+1);
        }
    }
    cout << ans;
}