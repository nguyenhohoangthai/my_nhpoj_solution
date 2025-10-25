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
int n, a[1005];

void solve(){
    int mn = oo;
    int pos = 0;
    fto(i, 1, n) mn = min(mn, a[i]);
    fto(i, 1, n) {
        if (a[i] == mn){
            cout << i-1;
            break;
        }
    }
}

int main(){
    fastio;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    solve();
}