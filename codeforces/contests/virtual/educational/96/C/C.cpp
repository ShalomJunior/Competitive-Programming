#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << 2 << endl;
    if (n == 2) {
        cout << 1 << " " << 2 << endl;
        return;
    }
    multiset<int> ms;
    for (int i = 1; i <= n; i++) ms.insert(i);
    cout << n - 2 << " " << n << endl;
    ms.erase(n - 2);
    ms.erase(n);
    ms.insert(n - 1);
    int cnt = 1;
    while (ms.size() > 1) {
        cnt++;
        int s = 0;
        for (int i : {1, 2}) {
            int x = *prev(ms.end());
            s += x;
            cout << x << " ";
            ms.erase(prev(ms.end()));
        }
        cout << endl;
        ms.insert((s + 1) / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
