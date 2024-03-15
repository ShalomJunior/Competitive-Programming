#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    vector<int> a;
    a.push_back(b[0]);
    for (int i = 1; i < n; i++) {
        if (a.back() <= b[i]) a.push_back(b[i]);
        else {
            a.push_back(b[i]);
            a.push_back(b[i]);
        }
    }
    cout << a.size() << endl;
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}