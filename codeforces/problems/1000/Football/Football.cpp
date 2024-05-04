#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<string, int> h;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        h[s]++;
    }

    int mx = 0;
    string ans;
    for (auto& [k, v] : h) {
        if (v > mx) {
            mx = v;
            ans = k;
        }
    }
    cout << ans << endl;
}