#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n = a.size();
    for (int i = 0; i < n; i++) {

    }
    cout << n << " " << d << endl;
    0LL+
    long long
        int n, d; cin >> n >> d;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                int s = a[i] + a[j] + a[k];

                if ((s % d) == 0) ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
