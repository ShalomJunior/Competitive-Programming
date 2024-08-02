#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int x = 0;
    int y = 0;
    int bad = 0;
    int good = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && b[i] <= 0) x++;
        else if (a[i] <= 0 && b[i] > 0) y++;
        else if (a[i] < 0 && b[i] < 0) bad++;
        else if (a[i] > 0 && b[i] > 0) good++;
        else {}
    }
    while (x < y && good) x++, good--;
    while (x > y && good) y++, good--;
    while (x < y && bad) y--, bad--;
    while (x > y && bad) x--, bad--;
    if (bad < good) {
        good -= bad;
        int need = abs(x - y);
        if (good <= need) {
            cout << min(x, y) + good;
        }
        else {
            good -= need;
            cout << max(x, y) + good / 2;
        }
    }
    else if (bad > good) {
        bad -= good;
        int need = abs(x - y);
        if (bad <= need) {
            cout << min(x, y);
        }
        else {
            bad -= need;
            cout << min(x, y) - (bad + 1) / 2;
        }
    }
    else {
        cout << min(x, y);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
