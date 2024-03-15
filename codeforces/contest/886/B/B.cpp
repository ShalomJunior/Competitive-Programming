#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int id, best = 0;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        if (a <= 10 && b > best) id = i, best = b;
    }
    cout << id << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}