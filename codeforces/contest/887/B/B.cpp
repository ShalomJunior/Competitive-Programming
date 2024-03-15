#include <bits/stdc++.h>
using namespace std;

const int N = 30;
vector<int> fib(N);

void init() {
    fib[0] = 0; fib[1] = 1;
    for (int i = 2; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void solve() {
    int n, k; cin >> n >> k;
    if (k >= 29) { cout << "0\n"; return; }
    int a = fib[k - 2], b = fib[k - 1], ans = 0;
    for (int i = 0; a * i <= n; i++) {
        int c = n - a * i;
        if (c % b == 0 && c / b >= i) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--)solve();
}