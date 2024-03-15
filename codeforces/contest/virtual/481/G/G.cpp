#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> s(n);
    vector<int> is_exam(n, -1), learn(m), day(m);
    for (int i = 0; i < m; i++) {
        int si, di, ci;
        cin >> si >> di >> ci;
        --si, --di;
        s[si].push_back(i);
        is_exam[di] = i;
        learn[i] = ci;
        day[i] = di;
    }
    auto comp = [&](int i, int j) {
        return day[i] < day[j];
        };
    set<int, decltype(comp)> q(comp);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        for (auto& c : s[i]) q.insert(c);
        if (is_exam[i] == -1) {
            if (!q.empty()) {
                int exam = *q.begin();
                ans[i] = exam + 1;
                learn[exam]--;
                if (!learn[exam]) q.erase(q.begin());
            }
        }
        else {
            int exam = is_exam[i];
            if (learn[exam]) { cout << -1 << endl; return; }
            ans[i] = m + 1;
        }
    }
    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}