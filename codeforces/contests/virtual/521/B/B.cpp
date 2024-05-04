#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> light(n);
    for (int i = 1; i < n - 1; i++) {
        if (!a[i]) {
            if (a[i - 1]) light[i].push_back(i - 1);
            if (a[i + 1]) light[i].push_back(i + 1);
        }
    }
    set<int> off;
    for (int i = 1; i < n - 1; i++) {
        if (light[i].size() == 2) {
            if (!off.count(light[i][0]) && !off.count(light[i][1])) {
                off.insert(light[i][1]);
            }
        }
    }
    cout << off.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}