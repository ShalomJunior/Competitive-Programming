#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    set<int> in;
    while (!in.count(a)) {
        in.insert(a);
        a = (a + b) % l;
    }
    cout << *prev(in.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}