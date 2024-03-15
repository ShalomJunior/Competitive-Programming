#include <bits/stdc++.h>
using namespace std;

const int N = 31;
void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (auto& c : x) cin >> c;
    for (int i = 1; i < n; i++) {
        int last = x[i - 1] ^ y[i - 1];
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (last & mask) {
                if (x[i] & mask) continue;
                else y[i] |= mask;
            }
        }
    }
    for (auto& c : y) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}