#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = n - 1; i > 0; i--) {
        int id = 0;
        for (int j = 0; j <= i; j++) {
            if (a[j] > a[id]) id = j;
        }
        if (id == 0) break;
        swap(a[id], a[i]);
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}