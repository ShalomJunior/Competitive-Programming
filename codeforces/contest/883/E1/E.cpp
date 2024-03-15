#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
vector<bool> a(N);
void prepare() {
    for (int i = 2; i < N; i++) {
        int cnt = 1 + i, mult = i * i;
        while (cnt + mult < N) {
            cnt += mult;
            a[cnt] = true;
            mult *= i;
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << (a[n] ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}