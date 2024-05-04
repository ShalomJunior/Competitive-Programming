#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> x, y;
    char card[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> card[i][j];
            if (card[i][j] == '*') {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    if (x[0] == x[1]) {
        int id = (x[0] ? 0 : 1);
        card[id][y[0]] = '*';
        card[id][y[1]] = '*';
    }
    else if (y[0] == y[1]) {
        int id = (y[0] ? 0 : 1);
        card[x[0]][id] = '*';
        card[x[1]][id] = '*';
    }
    else {
        card[x[0]][y[1]] = '*';
        card[x[1]][y[0]] = '*';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << card[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}