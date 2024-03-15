#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> s, to_add;
    for (int i = 0; i < 2 * n; i++) to_add.insert(i);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        s.insert(c);
        to_add.erase(c);
    }
    int x;
    do {
        x = *to_add.begin();
        to_add.erase(x);
        cout << x << endl;
        fflush(stdout);
        cin >> x;
        to_add.insert(x);
    } while (x != -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}