#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a)  cin >> i;
    bool b1 = true, b2 = true;
    int id1 = a[0], id2 = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] != id1) b1 = false;
        else {
            id1++;
            if (id1 > n) id1 %= n;
        }
        if (a[i] != id2) b2 = false;
        else {
            id2--;
            if (id2 == 0) id2 += n;
        }
    }
    cout << (b1 | b2 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}