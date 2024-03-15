#include <bits/stdc++.h>
using namespace std;

const int N = 31;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> x(n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < N; j++) {
            int m = 1 << j;
            if (1LL * m * a[i] > 1LL * a[i + 1]) {
                x[i] = j;
                break;
            }
        }
    }
    vector<int> y(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < N; j++) {
            int m = 1 << j;
            if (1LL * a[i - 1] <= 1LL * m * a[i]) {
                y[i] = j;
                break;
            }
        }
    }
    vector<long long> z(n);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (y[i] == 0) {
            if (z[i - 1] >= x[i - 1]) {
                z[i] = z[i - 1] - x[i - 1] + 1;
            }
        }
        else {
            z[i] = z[i - 1] + y[i];
        }
        ans += z[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}