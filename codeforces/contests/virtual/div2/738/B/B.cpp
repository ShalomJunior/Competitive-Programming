#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    if (count(s.begin(), s.end(), '?') == n) s[0] = 'B';
    vector<int> id;
    id.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') id.push_back(i);
    }
    for (int i = 1; i < id.size(); i++) {
        for (int j = id[i] - 1; j > id[i - 1]; j--) {
            s[j] = (s[j + 1] == 'B' ? 'R' : 'B');
        }
    }
    for (int i = id.back() + 1; i < n; i++) {
        s[i] = (s[i - 1] == 'B' ? 'R' : 'B');
    }
    for (auto& c : s) cout << c;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}