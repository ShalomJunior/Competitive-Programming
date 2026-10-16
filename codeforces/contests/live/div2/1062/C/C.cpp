#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> h;
    for (auto& c : a) {
        cin >> c;
        h[c]++;
    }
    sort(a.begin(), a.end());
    for (int g = a[k]; g > 0; g--) {
        auto it1 = lower_bound(a.begin(), a.end(), g);
        auto it2 = lower_bound(a.begin(), a.end(), 4 * g);
        int rem = it1 - a.begin() + it2 - it1 - h[g] - h[2 * g] - h[3 * g];
        if (rem <= k) {
            cout << g << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
