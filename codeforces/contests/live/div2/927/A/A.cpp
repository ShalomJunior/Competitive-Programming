#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    bool good = true;
    for (int i = 0; i < n; i++) {
        good &= a[i] <= b[i];
    }
    if (good) {
        cout << 0 << endl;
        return;
    }
    bool flag = false;
    int ans = 0;
    while (!flag) {
        ans++;
        a.push_back(1);
        sort(a.begin(), a.end());
        a.pop_back();
        flag = true;
        for (int i = 0; i < n; i++) {
            flag &= a[i] <= b[i];
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
