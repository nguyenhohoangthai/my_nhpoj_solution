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
long long n, k;
long long d(long long a, long long b) {
    if (b == 0) return 1LL;
    if (b & 1) return (a * d(a, b-1) % oo) % oo;
    ll tmp = d(a, b/2) % oo;
    return (tmp * tmp) % oo;
}

long long fac(long long x) {
    if (x == 0) return 1;
    return (x * fac(x-1) % oo) % oo;
}

long long C(int n, int k) {
    return (fac(n) % oo) * (d((fac(k) % oo * (fac(n-k) % oo)) % oo, oo - 2) % oo) % oo;
}

int main(){
    fastio;
    cin >> n >> k;
    cout << C(n-1, k-1);
}