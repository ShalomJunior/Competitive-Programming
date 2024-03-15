#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(4);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    for (int i = 0; i < 3; i++) {
        cout << a.back() - a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}