#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int div = 0, sum = 0;
    for (int x = 1; x <= n; x++) {
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                div++; sum += i;
                if (i != x / i) {
                    div++; sum += x / i;
                }
            }
        }
    }
    cout << div << " " << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}