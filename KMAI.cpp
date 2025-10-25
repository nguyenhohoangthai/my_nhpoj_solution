#include <bits/stdc++.h>
#define M 1000000007
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fi first
#define se second
using namespace std;

long long n, x, y, z, mx_v_1, mx_v_2, mx_t_1, mx_t_2, pv1, pv2, pt1, pt2, s;
const long long oo = 1000000000000007;
vector<vector<long long>> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    mx_v_1 = mx_v_2 = mx_t_1 = mx_t_2 = -oo;
    fto(i, 0, n-1) {
        cin >> x >> y >> z;
        a.push_back({x, y, z});
        s += x;
        if (mx_v_1 < mx_v_2) {
            if (mx_v_1 < y - x && y - x != mx_v_2) {
                pv1 = i;
                mx_v_1 = y - x;
            }
        }
        else {
            if (mx_v_2 < y - x && y - x != mx_v_1) {
                pv2 = i;
                mx_v_2 = y - x;
            }
        }
        if (mx_t_1 < mx_t_2) {
            if (mx_t_1 < z - x) {
                pt1 = i;
                mx_t_1 = z - x;
            }
        }
        else {
            if (mx_t_2 < z - x) {
                pt2 = i;
                mx_t_2 = z - x;
            }
        }
    }
    // cout << mx_v_1 << " " << pv1 << " " << mx_v_2 << " " << pv2 << " " << mx_t_1 << " " << pt1 << " " << mx_t_2 << " " << pt2 << "\n";
if (mx_v_1 < mx_v_2) {
        swap(mx_v_1, mx_v_2);
        swap(pv1, pv2);
    }
    if (mx_t_1 < mx_t_2) {
        swap(mx_t_1, mx_t_2);
        swap(pt1, pt2);
    }

    if (pv1 != pt1) {
        cout << s + mx_v_1 + mx_t_1 << "\n";
        cout << pv1 + 1 << " " << pt1 + 1 << "\n";
    }
    else {
        if (mx_v_1 + mx_t_2 >= mx_v_2 + mx_t_1) {
            cout << s + mx_v_1 + mx_t_2 << "\n";
            cout << pv1 + 1 << " " << pt2 + 1 << "\n";
        }
        else {
            cout << s + mx_v_2 + mx_t_1 << "\n";
            cout << pv2 + 1 << " " << pt1 + 1 << "\n";
        }
    }
    // cout << mx_v_1 << " " << pv1 << " " << mx_v_2 << " " << pv2 << " " << mx_t_1 << " " << pt1 << " " << mx_t_2 << " " << pt2 << "\n";
return 0;
}