#include <bits/stdc++.h>
using namespace std;

int g(int k) {
    int i = 0;
    while ((i + 1) * (i + 2) / 2 <= k)i++;
    return i;
}

void solve() {
    int n, k; cin >> n >> k;

    int p = g(k);
    vector<int> ans;
    for (int i = 1; i <= p; i++)
        ans.push_back(2 * i);

    int r = k - p * (p + 1) / 2;
    if (r == 1 && ans.size() == 1) ans.push_back(-ans.back() + 1);
    else if (r) {
        int minus = accumulate(ans.begin() + r, ans.end(), 0);
        ans.push_back(-minus - 1);
    }
    while ((int)ans.size() < n) {
        ans.push_back(-1000);
    }
    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}