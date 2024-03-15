#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

int go(int n, int m, vector<vector<int>>& a) {
    auto merge = [](vector<Mine>& a) {
        vector<Mine> ans;

        if (a.empty()) return ans;


        int n = a.size();
        sort(a.begin(), a.end());
        int L = a[0].F, R = a[0].S;
        for (int i = 1; i < n; i++) {
            if (a[i].F <= R) R = max(R, a[i].S);
            else {
                ans.push_back({ L, R });
                L = a[i].F, R = a[i].S;
            }
        }
        ans.push_back({ L, R });
        return ans;
        };
    vector<vector<Mine>> seg(3);
    for (int i = 0; i < m; i++) {
        seg[a[i][0] - 1].push_back({ a[i][1] - 1, a[i][2] - 1 });
    }
    auto red = merge(seg[0]);
    auto blue = merge(seg[1]);
    auto green = merge(seg[2]);
    vector<int> cnt(n);
    for (auto& vec : { red, blue, green }) {
        for (auto& [l, r] : vec) {
            for (int i = l; i <= r; i++) cnt[i]++;
        }
    }
    int ans = 0;
    for (auto& c : cnt) if (c == 3) ans++;
    return ans;
}

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<Mine>> seg(3);
    for (int i = 0; i < m; i++) {
        int c, l, r; cin >> c >> l >> r;
        --c, --l, --r;
        seg[c].push_back({ l, r });
    }
    vector<vector<int>> a;
    for (int i = 0; i < m; i++) {
        int c, l, r; cin >> c >> l >> r;
        a.push_back({ c - 1, l - 1, r - 1 });
    }
    go(n, m, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    int temp = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j += i) {
            for (int k = 1; k <= n; k += 2) {
                temp++;
            }
        }
    }


