#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(int n) {
    int i = 0;
    while ((1 << i) <= n)i++;
    return { 1 << i, 1 << (i + 1) };
}

void solve() {
    int n; cin >> n;
    if (n == 3) { cout << "1 2 3\n"; return; }
    vector<int> ans(n);
    auto g = f(n);
    int even = 1, odd = g.second + 1;
    int k = (n & 1) ? n - 1 : n;
    for (int i = 0; i < k; i++) {
        ans[i] = (i & 1) ? odd++ : even++;
    }
    k /= 2;
    if (k & 1) {
        ans[1] = g.first + 1;
        ans[3] |= g.first;
    }
    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}