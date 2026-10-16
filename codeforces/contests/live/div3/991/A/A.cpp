#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s.size());
    }
    int s = 0;
    int ans = 0;
    for (auto& c : a) {
        if (s + c <= m) {
            s += c;
            ans++;
        }
        else break;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
