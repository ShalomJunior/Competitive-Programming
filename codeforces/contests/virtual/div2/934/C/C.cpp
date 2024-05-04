#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (a[i])s.insert({ a[i], i });
    }
    set<int> ans;
    bool alice = true;
    while (!s.empty()) {
        auto [cnt, x] = *s.begin();
        s.erase(s.begin());
        if (alice) {
            ans.insert(x);
        }
        else {
            if (cnt > 1)s.insert({ cnt - 1, x });
        }
        alice = !alice;
    }
    int j = 0;
    while (ans.count(j))j++;
    cout << j << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}