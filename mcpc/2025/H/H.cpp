#include<bits/stdc++.h>
using namespace std;

const int T = 100;
const int INF = 1e9;
int get(vector<pair<int, int>>& inter, int k) {
    int n = inter.size();
    sort(inter.begin(), inter.end());
    multiset<int> ms;
    for (int j = 0, t = 0; t <= T; t++) {
        while (j < n && inter[j].first == t) {
            ms.insert(inter[j].second);
            j++;
        }
        if ((int)ms.size() >= k) return t;
        while (!ms.empty() && *ms.begin() <= t) {
            ms.erase(ms.begin());
        }
    }
    return INF;
}

void solve() {
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    vector<pair<int, int>> p(c);
    for (auto& [l, r] : p) {
        cin >> l >> r;
        l--;
        r--;
    }
    int tm = INF;
    auto go = [&](int mid) {
        int ntm = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ni = i + mid - 1;
                int nj = j + mid - 1;
                if (ni >= n || nj >= m) continue;
                vector<pair<int, int>> inter;
                for (auto& [l, r] : p) {
                    if (r < j && i <= l && l <= ni) {
                        inter.push_back({ j - r, nj - r });
                    }
                    if (r > nj && i <= l && l <= ni) {
                        inter.push_back({ r - nj, r - j });
                    }
                    if (l < i && j <= r && r <= nj) {
                        inter.push_back({ i - l, ni - l });
                    }
                    if (l > ni && j <= r && r <= nj) {
                        inter.push_back({ l - ni, l - i });
                    }
                    if (i <= l && l <= ni && j <= r && r <= nj) {
                        inter.push_back({ 0, max({l - i, ni - l, r - j, nj - r}) });
                    }
                }
                ntm = min(ntm, get(inter, k));
            }
        }
        if (ntm != INF) {
            tm = ntm;
            return true;
        }
        return false;
        };
    int lo = 1, hi = min(n, m);
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        go(mid) ? hi = mid : lo = mid + 1;
    }
    if (go(hi)) {
        cout << hi << " " << tm;
    }
    else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}