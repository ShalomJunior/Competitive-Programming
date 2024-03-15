#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> h(n);
    for (auto& c : h) cin >> c;
    sort(h.begin(), h.end());
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (h[i + 1] - h[i] < h[j + 1] - h[j]) j = i;
    }
    cout << h[j] << " ";
    for (int i = j + 2; i < n; i++) cout << h[i] << " ";
    for (int i = 0; i < j; i++) cout << h[i] << " ";
    cout << h[j + 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}