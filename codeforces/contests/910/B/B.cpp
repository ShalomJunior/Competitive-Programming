#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    int last = a.back(); a.pop_back();
    while (!a.empty()) {
        if (a.back() <= last) {
            last = a.back();
            a.pop_back();
            continue;
        }
        int x = a.back();
        a.pop_back();
        a.push_back(x / 2);
        a.push_back(x / 2 + x % 2);
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
