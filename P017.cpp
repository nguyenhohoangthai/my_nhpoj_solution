/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
#define ff first
#define ss second
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define pii pair<int, int>
#define pq priority_queue<pii, vector<pii>, greater<pii>>
#define ll long long
#define db double
#define sz(a) (int) a.size()
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define yes "YES"
#define no "NO"
#define PI acos(-1)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, dimension, cur_a, cur_b;
int main() {
    fastio;
    #define test "P017"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        dimension = n * n + m * m;
        cur_a = -1, cur_b = -1;
        while (1) {
            fto(a, 1, sqrt(dimension)) {
                int b = sqrt(dimension - a * a);
                if (a * a + b * b != dimension || (a == n && b == m) || (a == m && b == n) || b == 0 || a >= b) continue;
                if (dimension == n * n + m * m && a < n) continue;
                if (cur_a == -1 && cur_b == -1) {
                    cur_a = a;
                    cur_b = b;
                }
                else if (cur_a > a) {
                    cur_a = a;
                    cur_b = b;
                }
            }
            if (cur_a != -1 && cur_b != -1) break;
            ++dimension;
        }
        cout << cur_a << " " << cur_b << "\n";
    }
    return 0;
}