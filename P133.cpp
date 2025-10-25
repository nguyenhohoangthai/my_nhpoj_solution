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
int n, a[100005], b[100005], ans;

int main(){
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    fto(i, 1, n) ans = max(ans, abs(a[i] - b[i]));
    cout << ans;
}