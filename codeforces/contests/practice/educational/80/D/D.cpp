#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
const int N = 32;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int MASK = (1 << m) - 1;
    int l = 0, r = 0;
    auto check = [&](int mid) {
        set<int> in;
        set<pair<int, int>> past;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= mid) {
                    mask |= (1 << j);
                }
            }
            for (auto& [c, id] : past) {
                if ((mask | c) == MASK) {
                    l = i;
                    r = id;
                    return true;
                }
            }
            if (!in.count(mask)) {
                in.insert(mask);
                past.insert({ mask, i });
            }
        }
        return false;
        };
    int L = 0, R = INF;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid;
    }
    cout << l + 1 << " " << r + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
