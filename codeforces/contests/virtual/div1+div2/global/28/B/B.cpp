#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, -1);
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    for (int i = k - 1; i < n; i += k) {
        a[i] = *s.begin();
        s.erase(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = *s.begin();
            s.erase(a[i]);
        }
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}