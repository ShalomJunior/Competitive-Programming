#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    map<int, int> h;
    multiset<int> ms;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        h[x]++;
        ms.insert(x);
    }
    if (k == 3) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    int m = k - 2;
    for (int i = 1; i * i <= k; i++) {
        if (m % i == 0) {
            if (h[i]-- && h[m / i]) {
                cout << i << " " << m / i << endl;
                return;
            }
            else {
                h[i]++;
            }
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
