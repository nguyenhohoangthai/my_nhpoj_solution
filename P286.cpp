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
int a, b;

void solve(int n, int m){
    if (n % m == 0) {
        cout << n / m;
        return;
    }
    cout << n / m << " ";
    solve(m, n % m);
}

int main(){
    fastio;
    cin >> a >> b;
    solve(a, b);
}