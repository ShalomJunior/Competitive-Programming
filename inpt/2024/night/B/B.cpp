#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> h;
    for (auto& c : s) h[c]++;
    vector<int> a;
    for (auto& c : { 'L', 'U', 'C', 'K', 'Y' }) {
        a.push_back(h[c]);
    }
    int mx = *max_element(a.begin(), a.end());
    int ans = 1e9;
    for (int i = 1; i <= mx + 10; i++) {
        int curr = 0;
        for (auto& c : a) curr += abs(i - c);
        ans = min(ans, curr);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

