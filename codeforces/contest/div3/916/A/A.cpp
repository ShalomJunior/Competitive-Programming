#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n; string s;
    cin >> n >> s;
    vector<int> a(N);
    for (auto& c : s) {
        a[c - 'A']++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] > i) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
