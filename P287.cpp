#include <bits/stdc++.h>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
	int n, x; cin >> n >> x;
	int ans = 0;
	while (n--) {
		int t; cin >> t;
		if (t == x) ++ans;
	}
	cout << ans;
}