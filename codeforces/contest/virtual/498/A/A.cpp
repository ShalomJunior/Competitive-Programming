#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a % 2 == 0)a -= 1;
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}