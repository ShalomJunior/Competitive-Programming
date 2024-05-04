#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mask = 0;
    vector<int> ans;
    while (n) {
        int best = -1;
        for (int i = 0; i < n; i++) {
            if (best == -1 || ((mask | a[i]) > (mask | a[best]))) best = i;
        }
        if ((mask | a[best]) == mask)break;
        ans.push_back(a[best]);
        mask |= a[best];
        a.erase(a.begin() + best);
        n--;
    }
    for (auto& c : ans) cout << c << " ";
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}