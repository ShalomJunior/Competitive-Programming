#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    set<int> s;
    for (auto& c : a) {
        if (c - 1 && !s.count(c - 1)) s.insert(c - 1);
        else if (!s.count(c)) s.insert(c);
        else s.insert(c + 1);
    }
    cout << s.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}