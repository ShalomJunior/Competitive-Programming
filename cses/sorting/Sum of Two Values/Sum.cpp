#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; cin >> n >> t;

    unordered_map<int, int>f, s;
    for (int i = 0; i < n; i++) {
        cout << i << endl;
        int a; cin >> a;
        if (f.find(a) == f.end()) f[a] = i + 1;
        else s[a] = i + 1;
    }

    for (auto& [k, v] : f) {
        int comp = t - k;
        if (f.find(comp) != f.end()) {
            if (comp != k) {
                cout << f[k] << " " << f[comp] << endl;
                return 0;
            }
            else {
                if (s.find(k) != s.end()) {
                    cout << f[k] << " " << s[k] << endl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}