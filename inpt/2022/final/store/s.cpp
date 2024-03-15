#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, a, b, c; cin >> N >> a >> b >> c;
    cout << ((a + b + c < 2 * N) ? "possible" : "impossible") << endl;
}
