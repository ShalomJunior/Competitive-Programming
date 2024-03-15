#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    if (a[0] == a.back()) {
        cout << (count(a.begin(), a.end(), a[0]) >= k ? "YES" : "NO") << endl;
        return;
    }
    else {
        int i = n - 1, cnt = 0;
        for (; i >= 0 && cnt < k; i--) {
            if (a[i] == a.back()) cnt++;
        }
        if (cnt < k) { cout << "NO" << endl; return; }
        cnt = 0;
        for (; i >= 0; i--) {
            if (a[i] == a[0]) cnt++;
        }
        cout << (cnt < k ? "NO" : "YES") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}