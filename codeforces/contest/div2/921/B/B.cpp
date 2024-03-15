#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    set<int> s;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (n <= i) s.insert(x / i);
            if (n <= x / i) s.insert(i);
        }
    }
    cout << *prev(s.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
