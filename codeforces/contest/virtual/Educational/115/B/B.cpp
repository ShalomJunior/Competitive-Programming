#include <bits/stdc++.h>
using namespace std;

const int N = 5;
void solve() {
    int n; cin >> n;
    vector<vector<int>>a(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            int b; cin >> b;
            if (b)a[j].push_back(i);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            set<int> all;
            all.insert(a[i].begin(), a[i].end());
            all.insert(a[j].begin(), a[j].end());
            int x = a[i].size();
            int y = a[j].size();
            int z = all.size();
            if (x >= n / 2 && y >= n / 2 && z == n) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}