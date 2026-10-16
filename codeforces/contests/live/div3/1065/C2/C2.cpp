#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    for (int j = N; j >= 0; j--) {
        int s = 0;
        int m = 1 << j;
        for (int i = 0; i < n; i++) {
            int x = (a[i] & m) ? 1 : 0;
            int y = (b[i] & m) ? 1 : 0;
            if (x != y) {
                i & 1 ? s++ : s--;
            }
            if (s == -2 || s == 2) s = 0;
        }
        if (s == -1) {
            cout << "Ajisai" << endl;
            return;
        }
        if (s == 1) {
            cout << "Mai" << endl;
            return;
        }
    }
    cout << "Tie" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
