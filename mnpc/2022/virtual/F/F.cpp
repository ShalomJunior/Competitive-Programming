#include <bits/stdc++.h>
using namespace std;

const int N = 105;
void solve() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> a(n);
    for (auto& [l, r] : a) cin >> l >> r;
    sort(a.begin(), a.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
        });
    vector<vector<bool>> cpu(c, vector<bool>(N));
    for (int i = 0; i < c; i++) cpu[i][0] = true;
    for (int i = 0; i < n; i++) {
        bool f = false;
        for (int k = a[i].first; !f && k <= a[i].second; k++) {
            for (int j = 0; j < c; j++) {
                if (!cpu[j][k]) {
                    cpu[j][k] = true;
                    f = true;
                    break;
                }
            }
        }
        if (!f) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}