#include <bits/stdc++.h>
using namespace std;

const int N = 4;
void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& s : a) cin >> s;
    for (int i = n - 1; i >= 0; i--) {
        string s = a[i];
        for (int j = 0; j < N; j++) {
            if (s[j] == '#') {
                cout << j + 1 << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
