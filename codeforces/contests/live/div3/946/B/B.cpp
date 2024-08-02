#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<char> all(s.begin(), s.end());
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    map<char, char> h;
    int i = 0, j = all.size() - 1;
    while (i <= j) {
        h[all[j]] = all[i];
        h[all[i]] = all[j];
        i++, j--;
    }
    for (auto& c : s) {
        assert(h.count(c));
        cout << h[c];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
