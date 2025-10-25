#include <bits/stdc++.h>
#define oo 1e9 + 7
#define maxN 1e5 + 5
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
using namespace std;
int n, k, b, pos, x[1005];
int main(){
    fastio;
    cin >> n >> k >> b;
    fto(i, 1, n) {
        cin >> x[i];
    }
    while (k > 0) {
        ++pos;
        fto(i, 1, n) {
            if (pos == x[i]) {
                k += b;
                break;
            }
        }
        k -= 1;
    }
    cout << pos;
}