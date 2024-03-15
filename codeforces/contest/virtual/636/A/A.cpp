#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int n; cin >> n;
    for (int i = 2; i < N; i++) {
        int m = (1 << i) - 1;
        if (n % m == 0) {
            cout << n / m << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}