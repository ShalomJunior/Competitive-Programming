#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int>& v) {
    set<int> s(v.begin(), v.end());
    return (s.size() != v.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int t = 0, r = 0, c = 0;
    vector<vector<int>> f(n, vector<int>(n));
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            f[i][j] = a;
            s[j][i] = a;
            if (i == j)t += f[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        r += comp(f[i]);
        c += comp(s[i]);
    }
    cout << t << " " << r << " " << c << endl;
}