#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        h[v]++;
    }

    int mx = 0;
    for (auto& [k, v] : h)
        mx = max(mx, v);

    cout << mx << " " << h.size() << endl;
}