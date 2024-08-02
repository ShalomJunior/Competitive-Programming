#include <bits/stdc++.h>
using namespace std;

const int N = 500;
void solve() {
    cerr << endl;
    int n;
    cin >> n;
    vector<int> t(n);
    for (auto& c : t) cin >> c;
    sort(t.begin(), t.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
