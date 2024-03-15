#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> vec(n), mn(n), mx(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        if (!i || i && vec[i - 1] != vec[i]) mn[i] = mx[i] = vec[i];
    }
    set<int> M, m;
    for (int last = 1, i = 0; i < n; i++) {
        if (mn[i]) {
            for (int j = last; j < mn[i]; j++) M.insert(j), m.insert(j);
            last = mn[i] + 1;
        }
        else {
            mn[i] = *m.begin();
            mx[i] = *prev(M.end());
            m.erase(m.begin());
            M.erase(prev(M.end()));
        }
    }
    auto g = [&](vector<int>& v) {
        for (auto& c : v) cout << c << " ";
        cout << endl;
        };
    g(mn), g(mx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}