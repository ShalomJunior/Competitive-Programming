#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < n; i++) {
        int k; cin >> k; --k;
        a[k]++;
    }
    vector<int> cost(m);
    for (auto& c : cost) cin >> c;
    vector<int> vec = cost;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < a[i]; j++)
            vec.push_back(cost[i]);
    }
    sort(vec.begin(), vec.end());
    cout << accumulate(vec.begin(), vec.begin() + n, 0LL) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}