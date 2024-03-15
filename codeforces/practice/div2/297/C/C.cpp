#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    sort(a.begin(), a.end());
    int ans = 0;
    while (a.size() >= 4) {
        int W = a.back();
        a.pop_back();
        if (a.back() == W - 1)W--;
        if (a.back() != W)continue;
        a.pop_back();
        int H = a.back();
        bool flag = false;
        a.pop_back();
        while (a.size() > 0) {
            int h = a.back();
            a.pop_back();
            if (h == H - 1)H--;
            if (h == H) {
                flag = true;
                break;
            }
            H = h;
        }
        if (flag)ans += W * H;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
