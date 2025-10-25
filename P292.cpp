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

pair<pair<int, int>, int> ex_gcd(int a, int b) {
    if (b == 0) return {{1, 0}, a};
    pair<pair<int, int>, int> t = ex_gcd(b, a % b);
    int x = t.first.second;
    int y = t.first.first - a / b * x;
    int d = t.second;
    return {{x, y}, d};
}

int main(){
    fastio;
    int x, y; cin >> x >> y;
    pair<pair<int, int>, int> ans = ex_gcd(x, y);
    cout << ans.ff.ff << " " << ans.ff.ss;
}