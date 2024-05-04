#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    int i = 0;
    int y = 0;
    while (y < x) {
        i++;
        y += i;
    }
    int sup = y - x;
    if (sup == 1) i++;
    cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
