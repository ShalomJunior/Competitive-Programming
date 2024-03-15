#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        v[i] = val;
        h[val]++;
    }

    int mx = 0;
    for (auto& [k, v] : h) {
        mx = max(mx, v);
    }

    unordered_map<int, int>ans;
    for (int i = 0; i < n; i++) {
        ans[v[i]]++;
        if (ans[v[i]] == mx) {
            cout << v[i] << endl;
            break;
        }
    }
}