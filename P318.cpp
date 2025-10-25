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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int m, n, a[105][105], ans;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

int check_min(int i, int j, vector<pair<int, int>> x) {
	for (auto t : x) {
		if (i + t.ff == 0 || j + t.ss == 0 || i + t.ff == m+1 || j + t.ss == n+1) continue;
		if (a[i + t.ff][j + t.ss] > a[i][j]) return 0;
	}
	return 1;
}
int check_max(int i, int j, vector<pair<int, int>> x) {
	for (auto t : x) {
		if (i + t.ff == 0 || j + t.ss == 0 || i + t.ff == m+1 || j + t.ss == n+1) continue;
		if (a[i + t.ff][j + t.ss] < a[i][j]) return 0;
	}
	return 1;
}
int check(int i, int j) {
	vector<pair<int, int>> x;
	fto(i, 0, 7) x.pb({dx[i], dy[i]});
	if (check_min(i, j, x)) return 1;
	if (check_max(i, j, x)) return 1;
	return 0;
}
int main() {
    fastio;
 	cin >> m >> n;
 	fto(i, 1, m) {
 		fto(j, 1, n) cin >> a[i][j];
 	}
 	fto(i, 1, m) {
 		fto(j, 1, n) {
 			if (check(i, j)) ++ans;
 		}
 	}
 	cout << ans << "\n";
    return 0;
}