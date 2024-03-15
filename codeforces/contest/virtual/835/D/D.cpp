#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);

    for (auto& c : v)
        cin >> c;

    int asc = false;
    for (int i = 1; i < n; i++) {
        if (v[i] != v[0]) {
            asc = (v[i] > 0);
            break;
        }
    }

    vector<bool> inv(n);
    for (int i = 1; i < n; i++) {
        if (asc)
            inv[i - 1] = v[i] >= v[i - 1];
        else
            inv[i - 1] = v[i] <= v[i - 1];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (inv[i] != inv[i + 1]);
    }

    cnt += (n == 3) ? 1 : 0;
    if (cnt > 1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }

}


int main() {
    int t; cin >> t;
    while (t--) solve();
}