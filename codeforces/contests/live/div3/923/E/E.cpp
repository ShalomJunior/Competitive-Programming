#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> use(k, n / k);
    for (int i = 0; i < n % k; i++)use[i]++;
    int x = 1;
    vector<int> ans(n);
    for (int i = 0; i < k; i++) {
        if (i & 1) {
            for (int j = 0; j < use[i]; j++)ans[i + j * k] = x + j;
        }
        else {
            for (int j = 0; j < use[i]; j++)ans[i + j * k] = x + use[i] - 1 - j;
        }
        x += use[i];
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
