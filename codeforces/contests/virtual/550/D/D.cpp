#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> h;
    int M = 0, last;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++h[a[i]];
        if (M < h[a[i]]) {
            last = i;
            M = h[a[i]];
        }
    }
    cout << n - M << endl;
    for (int i = last + 1; i < n; i++) {
        if (a[i] == a[last]) continue;
        cout << (a[i] < a[last] ? 1 : 2) << " " << i + 1 << " " << i << endl;
    }

    for (int i = last - 1; i >= 0; i--) {
        if (a[i] == a[last]) continue;
        cout << (a[i] < a[last] ? 1 : 2) << " " << i + 1 << " " << i + 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}