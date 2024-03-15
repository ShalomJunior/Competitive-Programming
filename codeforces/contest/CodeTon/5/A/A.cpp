#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    long long a = 0, b = 0;
    for (int i = 0; i < n + m; i++) {
        int x; cin >> x;
        i < n ? a += x : b += x;
    }
    if (a > b)cout << "Tsondu";
    else if (a == b)cout << "Draw";
    else cout << "Tenzing";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}