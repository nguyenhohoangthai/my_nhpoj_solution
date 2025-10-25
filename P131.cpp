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

long long fac(long long a) {
    if (a == 0) return 1;
    return a * fac(a-1) % oo;
}

pair<ll, ll> ex_gcd(ll n, ll x) {
    if (x == 0) return {1, 0};
    pair <ll, ll> t = ex_gcd(x, n % x);
    long long a = t.ss;
    long long b = t.ff - n / x * a;
    return {a, b};
}

long long C(long long a, long long b) {
    pair<ll, ll> t = ex_gcd(fac(b) * fac(a - b) % oo, oo);
    return (fac(a) * ((t.ff + oo) % oo)) % oo;
}

int main(){
    fastio;
    long long n, k; cin >> n >> k;
    cout << C(n+k-1, n-1);
}