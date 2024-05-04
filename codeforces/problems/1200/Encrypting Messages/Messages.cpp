#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c; cin >> n >> m >> c;
    vector<int> v(n);
    vector<int> b(m);
    for (auto& c : v) cin >> c;
    for (auto& c : b) cin >> c;

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < m; j++) {
            v[i + j] += b[j];
            v[i + j] %= c;
        }
    }

    for (auto& c : v)
        cout << c << " ";

    cout << endl;
}