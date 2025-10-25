#include <bits/stdc++.h>
using namespace std;
int n, x, a[100005];
vector <int> l;
int main(){
    cin >> n;
    l.push_back(0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i){
        if (a[i] > l[l.size()-1]) l.push_back(a[i]);
        else{
            int low = 0;
            int high = l.size()-1;
            int p = 0;
            while (low <= high){
                int mid = (low + high) / 2;
                if (l[mid] >= a[i]) high = mid - 1;
                else{
                    low = mid + 1;
                    p = mid;
                }
            }
            l[p+1] = a[i];
        }
    }
    cout << l.size()-1;
}