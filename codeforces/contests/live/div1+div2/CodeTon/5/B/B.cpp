#include <bits/stdc++.h>
using namespace std;

const int N = 31;
bool good(int a, int x) {
    for (int i = 0; i < N; i++) {
        if (((a >> i) & 1) && !((x >> i) & 1)) return false;
    }
    return true;
}

void solve() {
    int n, x; cin >> n >> x;
    int ans = 0;
    for (int k = 0; k < 3; k++) {
        bool go = true;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (go && good(ans | a, x)) ans |= a;
            else go = false;
        }
    }
    cout << ((ans == x) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}