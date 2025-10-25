/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
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
#define int long long
#define db double
#define sz(a) (int) a.size()
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define yes "YES"
#define no "NO"
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 500005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a >= b ? (a = b) : 0);};
int n, temp[maxN], mn, point, sum, f[maxN];
pii a[maxN];
vector<int> st;
signed main() {
    fastio;
//    if (fopen("sinh.inp", "r")) {
//        freopen("sinh.inp", "r", stdin);
//        freopen("sinh.out", "w", stdout);
//    }
cin >> n;
    mn = oo;
    fto(i, 1, n) {
        cin >> temp[i];
        sum += temp[i];
        if (minimize(mn, temp[i])) point = i;;
    }
    int mark = 1;
    fto(i, 1, n - point) a[i] = {i, temp[point + i]};
    fto(i, n - point + 1, n) a[i] = {i, temp[mark++]};
//    fto(i, 1, n) cout << "{" << a[i].ff << ", " << a[i].ss << "} ";
    fdto(i, n, 1) {
        if (sz(st) <= 1 || a[i].ss > a[st.back()].ss) st.pb(a[i].ff);
        else {
            while (1) {
                if (sz(st) <= 1 || a[st.back()].ss < a[i].ss) break;
                int currentIndex = st.back();
                int previousIndex = st[sz(st) - 2];
                int delta = a[currentIndex].ss - a[previousIndex].ss;
                int start_time = previousIndex - currentIndex;
                int duration = currentIndex - a[i].ff;
                f[start_time] += delta;
                f[start_time + duration] -= delta;
                st.pop_back();
            }
            st.pb(a[i].ff);
        }
    }
    while (1) {
        if (sz(st) <= 1) break;
        int currentIndex = st.back();
        int previousIndex = st[sz(st) - 2];
        int delta = a[currentIndex].ss - a[previousIndex].ss;
        int start_time = previousIndex - currentIndex;
        int duration = currentIndex;
        f[start_time] += delta;
        f[start_time + duration] -= delta;
        st.pop_back();
    }
    fto(i, 1, n) f[i] += f[i-1];
    fto(i, 1, n) {
        sum -= f[i];
        cout << sum << "\n";
    }
    return 0;
}