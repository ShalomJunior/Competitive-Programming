#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string ans = "";
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            ans += 'a' + i;
            ans += 'a' + j;
        }
    }
    string
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}