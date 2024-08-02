#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
const int MOD = 37;
vector<int> fib(N);

void init() {
    fib[1] = 1;
    for (int i = 2; i < N; i++) {
        fib[i] = fib[i - 2] + fib[i - 1];
        fib[i] %= MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << fib[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--) solve();
}

