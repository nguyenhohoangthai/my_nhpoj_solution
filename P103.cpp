#include <bits/stdc++.h>
using namespace std;
int n, s, f[100005], k;
char type;
vector<long long> a;

int main(){
    cin >> n;
    s = a.size();
    for (int i = 1; i <= n; ++i){
        cin >> type >> k;
        if (type == 'r'){
            if (s == 0) {
                cout << "Wrong!" << "\n";
                continue;
            }
            else if (s == 1){
                if (a[0] == k){
                    cout << "Wrong!" << "\n";
                    s = 0;
                    a.erase(a.begin());
                    continue;
                }
                else{
                    cout << "Wrong!" << "\n";
                    continue;
                }
            }
            else{
                int low = 0;
                int high = s-1;
                int p = -1;
                while (low <= high){
                    int mid = (low + high) / 2;
                    if (a[mid] == k){
                        p = mid;
                        break;
                    }
                    else if (a[mid] < k) low = mid + 1;
                    else high = mid - 1;
                }
                if (p == -1) cout << "Wrong!" << "\n";
                else {
                    a.erase(a.begin()+p);
                    --s;
                    if (s % 2 == 1) cout << a[s/2] << "\n";
                    else{
                        if ((a[s/2-1] + a[s/2]) % 2 == 0) cout << (a[s/2-1] + a[s/2]) / 2 << "\n";
                        else cout << (a[s/2-1] - 1 + a[s/2]) / 2 << ".5" << "\n";
                    }
                }
            }
        }
        else if (type == 'a'){
            if (s == 0) a.push_back(k);
            else{
                int low = 0;
                int high = s-1;
                int p = -1;
                while (low <= high){
                    int mid = (low + high) / 2;
                    if (a[mid] <= k){
                        p = mid;
                        low = mid + 1;
                    }else high = mid - 1;
                }
                if (p != -1) a.insert(a.begin()+p+1, k);
                else a.insert(a.begin(), k);
            }
            ++s;
            if (s % 2 == 1) cout << a[s/2] << "\n";
            else{
                if ((a[s/2-1] + a[s/2]) % 2 == 0) cout << (a[s/2-1] + a[s/2]) / 2 << "\n";
                else cout << (a[s/2-1] - 1 + a[s/2]) / 2 << ".5" << "\n";
            }
        }

    }
}