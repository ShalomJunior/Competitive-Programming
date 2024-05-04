#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n * n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int mat[n][n];
    mat[0][0] = a[0];
    for (int i = 1; i < n; i++) mat[i][0] = mat[i - 1][0] + c;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            mat[i][j] = mat[i][j - 1] + d;
        }
    }
    vector<int> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x.push_back(mat[i][j]);
        }
    }
    sort(x.begin(), x.end());
    cout << (x == a ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
