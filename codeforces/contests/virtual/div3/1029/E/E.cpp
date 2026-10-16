#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    vector<vector<bool>> A(n + 1, vector<bool>(2));
    vector<vector<bool>> B(n + 1, vector<bool>(2));
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            cout << i + 1 << endl;
            return;
        }
        int t = i & 1;
        cout << a[i] << " " << b[i] << endl;
        if (A[a[i]][t ^ 1] || B[b[i]][t ^ 1]) {
            cout << i + 1 << endl;
            return;
        }
        A[a[i]][t] = true;
        B[b[i]][t] = true;
    }
    cout << "hell" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}