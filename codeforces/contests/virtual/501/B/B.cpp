#include <bits/stdc++.h>
using namespace std;

bool shuffle(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

void solve() {
    int n; string s, t;
    cin >> n >> s >> t;
    if (!shuffle(s, t)) { cout << -1 << endl; return; }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i])continue;
        for (int j = i + 1; j < n; j++) {
            if (s[j] == t[i]) {
                for (int k = j - 1; k >= i; k--) {
                    ans.push_back(k);
                    swap(s[k], s[k + 1]);
                }
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c + 1 << " ";
    if (ans.size()) cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}