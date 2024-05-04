#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    vector<int> a(N);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            char c; cin >> c;
            a[c - 'a']++;
        }
    }
    int ans = 10;
    for (int i = 0; i < N; i++) {
        int curr = 0;
        for (int j = 0; j < N; j++) {
            if (j != i) {
                curr += (a[j] + 1) / 2;
            }
        }
        ans = min(ans, curr);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
