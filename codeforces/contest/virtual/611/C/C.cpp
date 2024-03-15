#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    set<char> let;
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        let.insert(c);
    }
    long long ans = 0;
    vector<vector<int>> a(26);
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a'].push_back(i);
        vector<int> id;
        for (int i = 0; i < 26; i++) {
            if (!let.count('a' + i) && !a[i].empty()) {
                id.push_back(a[i].back());
            }
        }
        sort(id.begin(), id.end());
        if (!id.empty()) ans += i - id.back();
        else ans += i + 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}