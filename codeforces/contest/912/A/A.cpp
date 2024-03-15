#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (k == 1) {
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO");
    }
    else cout << "YES";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
