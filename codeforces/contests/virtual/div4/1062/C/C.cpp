#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int e = 0, o = 0;
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        c % 2 == 0 ? e++ : o++;
    }
    if (e > 0 && o > 0) {
        sort(a.begin(), a.end());
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