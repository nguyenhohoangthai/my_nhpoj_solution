/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fat(i, a) for (auto i : a)
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
long long a1, b1, c1, a2, b2, c2, a3, b3, c3, t1, t2, t3, y, z;
int main() {
    fastio;
    cin >> t1 >> t2 >> t3;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> c1 >> c2 >> c3;

    for (long long x = 0; x <= 10000000LL; ++x) {
    	long long d1 = t1 - a1*x;
    	long long d2 = t2 - a2*x;
    	z = (d1*b2 - d2*b1) / (c1*b2 - c2*b1);
    	y = (d1 - c1*z) / b1;
    	if (a1 * x + b1 * y + c1 * z == t1 && a2 * x + b2 * y + c2 * z == t2 && a3 * x + b3 * y + c3 * z == t3) {
    		cout << x << " " << y << " " << z << " ";
    		break;
    	}
    }
    return 0;
}