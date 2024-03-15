#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto& c : v)
        cin >> c;

    unordered_map<int, pair<int, int>> h;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            if (v[j] == 1) h[i].first++;
            else h[i].second++;
        }
    }

    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += min(h[i].first, h[i].second);

    cout << ans << endl;
}