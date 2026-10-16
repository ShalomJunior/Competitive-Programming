#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 5) {
        cout << -1 << endl;
        return;
    }
    stringstream ss;
    for (int i = 1; i <= n; i += 2) {
        if (i != 5) ss << i << " ";
    }
    ss << "5 4 2 ";
    for (int i = 6; i <= n; i += 2) {
        ss << i << " ";
    }

    cout << ss.str() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
