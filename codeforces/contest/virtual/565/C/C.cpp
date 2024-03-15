#include <bits/stdc++.h>
using namespace std;

vector<int> base = { 4, 8, 15, 16, 23, 42 };

void solve() {
    int n; cin >> n;
    vector<set<int>> a(6);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int j = lower_bound(base.begin(), base.end(), x) - base.begin();
        a[j].insert(i);
    }
    int taken = 0;
    while (taken < n) {
        int last = -1;
        for (int i = 0; i < base.size(); i++) {
            auto it = lower_bound(a[i].begin(), a[i].end(), last + 1);
            if (a[i].empty() || it == a[i].end()) {
                cout << n - taken << endl;
                return;
            }
            last = *it;
            a[i].erase(it);
        }
        taken += 6;
    }
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}