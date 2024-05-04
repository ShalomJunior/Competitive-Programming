#include <bits/stdc++.h>
using namespace std;

bool islower(char c) {
    char b = c;
    return c == tolower(c);
}

void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<pair<char, int>> up, low;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (!low.empty()) low.pop_back();
        }
        else if (s[i] == 'B') {
            if (!up.empty()) up.pop_back();
        }
        else {
            islower(s[i]) ? low.push_back({ s[i], i }) : up.push_back({ s[i], i });
        }
    }
    vector<pair<char, int>> ans;
    for (auto& p : low) ans.push_back(p);
    for (auto& p : up) ans.push_back(p);
    sort(ans.begin(), ans.end(), [&](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
        });
    for (auto& p : ans) cout << p.first;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
