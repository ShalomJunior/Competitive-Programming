#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>>v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            v[i][j] = c;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            string s;
            s.push_back(v[i][j]);
            s.push_back(v[i][j + 1]);
            s.push_back(v[i + 1][j]);
            s.push_back(v[i + 1][j + 1]);
            sort(s.begin(), s.end());
            if (s == "acef") cnt++;
        }
    }
    cout << cnt << endl;
}