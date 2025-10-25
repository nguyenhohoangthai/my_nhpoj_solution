#include <bits/stdc++.h>
#define oo 1000000007
#define pb push_back
#define ff first
#define ss second
#define fto(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
int n, d, a[200005], ans;

void solve(){
	int left = 1;
	int right = 2;
	while (n > 1){
		if (a[right] - a[left] <= d){
			++ans;
			n -= 2;
			left += 2;
			right = left + 1;
		}
		else{
			n -= 1;
			left += 1;
			right = left + 1;
		}
	}
    cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    fto(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    solve();
}