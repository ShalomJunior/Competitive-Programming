#include <bits/stdc++.h>
using namespace std;

int go(int n, int max) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    int ans = 0;
    for (int i = max; i > 0; i -= 2) {
        ans += go(n - i, i);
    }
    return ans;
}

void solve() {
    for (int i = 4; i < 500; i += 2) {
        cout << "i : " << i << " " << go(i, i - 2) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}