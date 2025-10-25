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
int n, v, x, ans;

int main(){
    fastio;
    cin >> n >> v;
    fto(i, 1, n) {
        cin >> x;
        ans = max(ans, v + x);
        v += x;
    }
    cout << ans;
}