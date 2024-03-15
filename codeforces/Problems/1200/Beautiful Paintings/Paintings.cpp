#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        s.insert(v);
        h[v]++;
    }

    int ans = 0;

    while (!s.empty()) {
        ans += s.size() - 1;
        for (auto& [k, v] : h) {
            v--;
            if (v == 0) {
                s.erase(v);
                s.erase(k);
            }
        }
    }

    cout << ans << endl;
}