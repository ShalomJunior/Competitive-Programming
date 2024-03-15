#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int M = *max_element(a.begin(), a.end());
    vector<bool> b(M + 1);
    for (int i = 0; i < n; i++) b[a[i]] = true;
    int cnt = count(b.begin(), b.end(), true);
    for (int i = M; i > 0; i--) {
        if (b[i]) continue;
        int x = 0;
        for (int j = 2; i * j <= M; j++) {
            if (b[i * j]) x = gcd(x, i * j);
        }
        if (x == i) b[i] = true;
    }
    int tot = count(b.begin(), b.end(), true);
    cout << tot - cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}