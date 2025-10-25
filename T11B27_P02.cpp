#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fllto(i, a, b) for (long long i = a; i <= b; ++i)
#define flldto(i, a, b) for (long long i = a; i >= b; --i)
#define fvt(i, g) for (int i : g)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define open(a) freopen(a".inp", "r", stdin); freopen(a".out", "w", stdout);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text 3\Packages\User
map<long long, long long> a;
vector<long long> f;
long long mark[105];
int main(){
    fastio;
    long long n;
    while (cin >> n) {
        ++a[n];
        f.pb(n);
    }
    for (auto x : f) {
        if (mark[x] == 0) {
            mark[x] == 1;
            cout << a[x] << " ";
        }
    }
    return 0;
}