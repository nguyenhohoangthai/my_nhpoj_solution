/*Hoang Thai*/
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
const int base = 311;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};

struct node {
int k, p, q;
    node() {}
    node(int k, int p, int q) : k(k), p(p), q(q) {}
};

int n, a[maxN], hs[maxN];
vector<int> uoc;
vector<node> ans;

int lt(int a, int b) {
    if (b == 0) return 1;
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % oo;
        b /= 2;
        a = (a * a) % oo;
    }
    return res;
}

void get(int x) {
    for (int i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            uoc.pb(i);
            if (x / i == i) break;
            uoc.pb(x/i);
        }
    }
}

int main() {
    fastio;
    #define test "P547"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i];
        hs[i] = hs[i-1] + lt(base, a[i]);
    }

    get(n);
    sort(uoc.begin(), uoc.end());

    for (int part : uoc) {
        int cur = hs[part];
        int cnt_cur = 1;
        int nxt_cur = -1;
        int cnt_nxt_cur = 0;
        int ok = 1;

        for (int i = part * 2; i <= n; i += part) {
            int j = i - part + 1;
            int values = hs[i] - hs[j-1];

            if (values == cur) ++cnt_cur;
            else {
                if (nxt_cur == -1) {
                    nxt_cur = values;
                    cnt_nxt_cur = 1;
                }
                else {
                    if (values == nxt_cur) ++cnt_nxt_cur;
                    else {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if (ok && cnt_cur && cnt_nxt_cur) {
            if (cnt_cur < cnt_nxt_cur) swap(cnt_cur, cnt_nxt_cur);
            ans.pb(node(part, cnt_cur, cnt_nxt_cur));
        }
    }
    if (ans.empty()) cout << -1 << "\n";
    else {
        sort(ans.begin(), ans.end(), [](const node x, const node y) {
            return x.k < y.k;
        });
        cout << sz(ans) << "\n";
        for (node x : ans) cout << x.k << " " << x.p << " " << x.q << "\n";
    }
    return 0;
}