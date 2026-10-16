#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    int x = n;
    int j;
    for (j = 0; j < n; j++) {
        if (p[j] != x) {
            break;
        }
        x--;
    }
    auto it = find(p.begin(), p.end(), x);
    if (x) {
        reverse(p.begin() + j, it + 1);
    }
    for (auto& c : p)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}