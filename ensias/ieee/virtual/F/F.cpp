#include <bits/stdc++.h>

using namespace std;

int cost(vector<int>& a, int sz) {
    int ans = 0;
    for (auto& c : a) {
        ans += (sz - c) * (sz - c);
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    int ans = INT_MAX;
    for (int i = -100; i <= 100; i++) {
        ans = min(ans, cost(a, i));
    }
    cout << ans << endl;
}