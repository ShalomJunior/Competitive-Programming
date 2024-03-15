#include <bits/stdc++.h>

using namespace std;

int perfect(int n) {
    while (n % 10 && n % 10 < 5) {
        n += n % 10;
    }
    return n;
}

int reach(int n, int eq) {
    if (!(n % 10)) return n;
    int diff = eq - n;
    n += 20 * (diff / 20);

    while (n % 10 && n + n % 10 <= eq) {
        n += n % 10;
    }
    return n;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v) cin >> c;
    int mx = *max_element(v.begin(), v.end());

    if (mx & 1)mx += mx % 10;
    int eq = perfect(mx);
    for (auto& c : v) {
        if (c & 1) c += c % 10;
        if (reach(c, eq) != eq) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}