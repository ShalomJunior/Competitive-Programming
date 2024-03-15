#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, a, b, c; cin >> N >> a >> b >> c;
    cout << ((a + b + c <= 2 * N) ? "possible" : "impossible") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}