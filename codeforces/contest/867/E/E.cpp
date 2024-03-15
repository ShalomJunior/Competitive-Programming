#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n & 1) { cout << -1 << endl; return; }

    vector<queue<int>> v(26);
    int diff = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]) {
            v[s[i] - 'a'].push(i);
            diff++;
        }
    }

    set<pair<int, int>> mine;
    for (int i = 0; i < 26; i++) {
        int sz = (int)v[i].size();
        if (sz)mine.insert({ sz, i });
    }

    int ans = 0;
    while (mine.size() > 1) {
        int l = mine.begin()->S, r = prev(mine.end())->S;
        int i1 = v[l].front(), i2 = v[r].front();
        v[l].pop(); v[r].pop();
        swap(s[i1], s[i2]);
        ans++;

        auto it = *mine.begin();
        mine.erase(mine.begin());
        if (it.F > 1) { it.F--; mine.insert(it); }

        it = *prev(mine.end());
        mine.erase(prev(mine.end()));
        if (it.F > 1) { it.F--; mine.insert(it); }
    }

    if (mine.empty()) { cout << ans << endl; return; }

    int idx = mine.begin()->S;
    int last = 0;
    while (!v[idx].empty()) {
        int i = v[idx].front();
        char c = s[i];
        bool b = false;
        for (int j = last; j < n;j++) {
            if (s[j] != c && s[n - 1 - j] != c && n - 1 - i != i && s[n - 1 - i] != s[j]) {
                swap(s[i], s[j]);
                b = true; ans++;
                last = j;
                v[idx].pop();
                break;
            }
        }
        if (!b) { cout << -1 << endl;return; }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}