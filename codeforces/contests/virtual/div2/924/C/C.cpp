#include <bits/stdc++.h>
using namespace std;

vector<int> div(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> ans;
    auto divs = div(n - x);
    for (auto& c : divs) {
        if (c % 2 == 0 && (c + 2) / 2 >= x)ans.push_back(c);
    }
    divs = div(n + x - 2);
    for (auto& c : divs) {
        if (c % 2 == 0 && (c + 2) / 2 >= x)ans.push_back(c);
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}