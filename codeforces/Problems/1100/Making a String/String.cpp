#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, bool> h(n);
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    long long ans = 0;
    for (auto& b : v) {
        while (h[b] && b > 0)b--;
        ans += b;
        h[b] = true;
    }

    cout << ans << endl;
}