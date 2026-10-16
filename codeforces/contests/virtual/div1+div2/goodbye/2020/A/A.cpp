#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            s.insert(abs(a[i] - a[j]));
        }
    }
    cout << s.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}