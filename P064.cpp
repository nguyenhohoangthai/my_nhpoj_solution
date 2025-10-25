#include <bits/stdc++.h>
#define pb push_back
#define sz(a) a.size()
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int x, y, k, m, f[105][205][205];
int dp(int t, int s_1, int s_2) {
    // kiểm tra điều kiện nếu thời gian về 0 hoặc hai thùng đã đầy
// hoặc lượng nước hai thùng đã lớn hơn m thì dừng lại
if (t == 0 || (s_1 == x && s_2 == y)) return abs(s_1 + s_2 - m);
    if (f[t][s_1][s_2] != -1) return f[t][s_1][s_2];
    //khởi tạo biến res ban đầu bằng abs(s_1 + s_2 - m);
int res = abs(s_1 + s_2 - m);
    // trường hợp của hai thùng đang rỗng thì mình sẽ đổ đầy 1 trong 2 thùng
if (s_1 == 0 && s_2 == 0) res = min(res, min(dp(t-1, x, 0), dp(t-1, 0, y)));
    // trường hợp nếu hai thùng đều đầy
if (s_1 > 0) res = min(res, dp(t-1, 0, s_2));
    if (s_2 > 0) res = min(res, dp(t-1, s_1, 0));
    if (s_1 > 0 && s_2 > 0) {
        // nếu thùng 1 chưa đầy thì sẽ xuất hiện hai trường hợp là ta sẽ
// đổ nước từ thùng 2 sang thùng 1 hoặc đổ nước vào đầy thùng 1
if (s_1 < x) {
            res = min(res, dp(t-1, x, s_2));
            res = min(res, dp(t-1, x, s_2 - s_1));
        }
        // nếu thùng 2 chưa đầy thì sẽ tương tự như thùng 1
if (s_2 < y) {
            res = min(res, dp(t-1, s_1, y));
            if (y - s_2 >= s_1) res = min(res, dp(t-1, 0, s_2 + s_1));
            else res = min(res, dp(t-1, s_1 + s_2 - y, y));
        }
    }
    // trường hợp nếu thùng 1 đang rỗng và thùng 2 đang có nước (chưa chắc đã đầy hay không)
// xảy ra hai trường hợp là đổ đầy nước vào thùng 1 hoặc đồ nước từ thùng 2 sang thùng 1
if (s_1 == 0 && s_2 > 0) {
        res = min(res, dp(t-1, x, s_2));
        res = min(res, dp(t-1, x, s_2 - x));
    }
    // trường hợp nếu thùng 1 đang có nước và thùng 2 đang rỗng (thùng 1 chắc chắn đầy)
// xảy ra hai trường hợp là đổ nước trực tiếp đầy vào thùng 2 hoặc đổ hết nước từ thùng 1 sang
if (s_2 == 0 && s_1 > 0) {
        res = min(res, dp(t-1, s_1, y));
        res = min(res, dp(t-1, 0, s_1));
    }
    return f[t][s_1][s_2] = res;
}
int main() {
    fastio;
    cin >> x >> y >> k >> m;
    if (x > y) swap(x, y);
    memset(f, -1, sizeof f);
    // dp theo thời gian k. s_1, s_2 là số lượng nước hiện có trong thùng 1 và 2
cout << dp(k, 0, 0) << "\n";
    return 0;
}