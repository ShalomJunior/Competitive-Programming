#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    int sub = 0;
    for (auto& c : a) {
        cin >> c; cnt[c]++;
        if (c > k) sub += c - k;
    }
    int best, own = 0;
    for (int i = k; i > 0; i--) {
        int have = n - sub;
        if (have - have % i > own) {
            own = have - have % i;
            best = i;
        }
        sub += cnt[i];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}