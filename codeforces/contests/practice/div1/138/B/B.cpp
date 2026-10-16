#include<bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> id(m, vector<int>(N, -1));
    for (int i = 0; i < m; i++) {
        if (i > 0) id[i] = id[i - 1];
        id[i][t[i] - 'a'] = i;
    }
    vector<int> L(n, -1);
    for (int i = 0, j = 0; i < n; i++) {
        if (i) L[i] = L[i - 1];
        if (j < m && s[i] == t[j]) L[i] = j++;
    }
    vector<int> R(n + 1, m);
    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        R[i] = R[i + 1];
        if (j >= 0 && s[i] == t[j]) R[i] = j--;
    }
    for (int i = 0; i < n; i++) {
        if (L[i] == -1 || id[L[i]][s[i] - 'a'] == -1) {
            cout << "No" << endl;
            return;
        }
        int p = id[L[i]][s[i] - 'a'];
        if (R[i + 1] > p + 1) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}