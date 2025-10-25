#include<bits/stdc++.h>
using namespace std;
#define fto(i, a, b) for(int i = a; i<=b;i++)
#define ll long long
#define l first
#define r second
#define ii pair<int, int>
const ll maxN = 1e6;
ll n, m, t[maxN], ans;
bool cmp(ii x, ii y){
    return x.l < y.l;
}

set<int> st;
ii a[maxN];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    fto(i, 1, n) {
        cin >> t[i];
        st.insert(t[i]);
    }
    sort(t + 1, t + n + 1);
    fto(i, 1, m) {
        cin >> a[i].l >> a[i].r;
        st.insert(a[i].l);
    }
    priority_queue<int, vector<int>, greater<int>> mp;
    sort(a + 1, a + m + 1, cmp);
  //  fto(i, 1, m) cout << a[i].l << " " << a[i].r << '\n';
int i = 1;
    int j = 1;
    for (int w : st){
        while (j <= m && a[j].l <= w ){
            mp.push(a[j].r);
            j++;
        }
        while (mp.size() && mp.top() < w) mp.pop();
        while (i <= n && t[i] <= w){
          //  cout << t[i] << " ";
if (mp.size() && mp.top() >= w){
                ans++;
                mp.pop();
            }
            i++;
        //    cout << ans <<'\n';
        }
    }
    cout << ans;




return 0;
}