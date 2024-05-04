#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n;i++) {
        int x; cin >> x;
        ms.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        auto it = ms.lower_bound(i);
        if (it == ms.end()) {
            cout << i - 1 << endl;
            return;
        }
        else ms.erase(it);
    }
    cout << n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}