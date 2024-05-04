#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    vector<int> ans;
    while (!s.empty()) {
        int c = *s.begin();
        while (c <= n) {
            ans.push_back(c);
            s.erase(c);
            c *= 2;
        }
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}