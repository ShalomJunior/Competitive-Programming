#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    unordered_set<int> us;
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (us.count(a[i]))break;
        else us.insert(a[i]);
    }
    cout << i + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}