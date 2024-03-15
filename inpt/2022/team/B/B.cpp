#include <bits/stdc++.h>
using namespace std;

bool g(vector<int>& v) {
    set<int> s(v.begin(), v.end());
    return s.size() == v.size();
}

int main() {
    int n; cin >> n;
    int t = 0, r = 0, c = 0;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v; cin >> v;
            a[i][j] = b[j][i] = v;
            if (i == j) t += v;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!g(a[i]))r++;
        if (!g(b[i]))c++;
    }
    cout << t << " " << r << " " << c << endl;
}