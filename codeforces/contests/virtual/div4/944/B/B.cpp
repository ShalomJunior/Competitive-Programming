#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string r = s;
            swap(r[i], r[j]);
            if (r != s) {
                cout << "YES" << endl;
                cout << r << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}