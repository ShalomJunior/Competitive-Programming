#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v) cin >> c;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int ans = 0;
    vector<int> temp;
    int cp = 1;
    while (v.size() > 1) {
        vector<int> temp;
        for (int i = 0; i < v.size(); i += 2) {
            if (abs(v[i] - v[i + 1]) > cp) {
                cout << -1 << endl;
                return;
            }
            if (v[i] > v[i + 1])ans++;
            temp.push_back(min(v[i], v[i + 1]));
        }
        v.clear();
        v = temp;
        cp *= 2;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}