#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int zero = 0, neg = 0;
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        zero += (c == 0);
        neg += (c < 0);
    }
    if (zero || neg & 1) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << 1 << " " << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
