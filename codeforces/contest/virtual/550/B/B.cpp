#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int sum = 0;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x & 1 ? odd.push_back(x) : even.push_back(x);
        sum += x;
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    int lo = odd.size(), le = even.size();
    int m = min(lo, le);
    int ans1 = 0;
    for (int i = 0; i < m + 1; i++) {
        if (i < lo) ans1 += odd[i];
        if (i < m) ans1 += even[i];
    }
    int ans2 = 0;
    for (int i = 0; i < m + 1; i++) {
        if (i < le) ans2 += even[i];
        if (i < m) ans2 += odd[i];
    }
    cout << sum - max(ans1, ans2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}