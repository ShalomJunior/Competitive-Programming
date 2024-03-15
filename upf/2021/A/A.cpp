#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int dim = n / 2;
    vector<vector<int>>ans(dim, vector<int>(dim));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            ans[i / 2][j / 2] += x;
        }
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}