#include <bits/stdc++.h>
using namespace std;

int n, m;
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void out(vector<int>& v) {
    for (auto& c : v)cout << c << " ";
    cout << endl;
}

void solve() {
    cin >> n >> m;
    int cnt = 0;
    if (!is_prime(n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << i + 1 + j * n << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans[i][j] = ++cnt;
    }
    if (!is_prime(m)) {
        for (int i = 0; i < n; i++)out(ans[i]);
    }
    else {
        for (int start : {0, 1}) {
            for (int i = start; i < n; i += 2)out(ans[i]);
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}