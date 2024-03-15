#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;  cin >> n;
    vector<int> a(n);
    bool neg = true;
    for (auto& c : a) {
        cin >> c;
        neg &= c < 0;
    }
    if (neg) {
        cout << *max_element(a.begin(), a.end()) << endl;
        return;
    }
    long long odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) continue;
        i & 1 ? odd += a[i] : even += a[i];
    }
    cout << max(odd, even) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}