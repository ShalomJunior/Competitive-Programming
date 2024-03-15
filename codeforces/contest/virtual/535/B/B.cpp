#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        ms.insert(d);
    }
    int x = *prev(ms.end());
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ms.erase(ms.find(i));
            if (x / i != i) ms.erase(ms.find(x / i));
        }
    }
    cout << *prev(ms.end()) << " " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}