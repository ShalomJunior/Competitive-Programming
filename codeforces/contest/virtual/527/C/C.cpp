#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int m = 2 * n - 2;
    vector<string> words(2 * n - 2);
    for (auto& s : words) cin >> s;
    auto temp = words;
    sort(temp.begin(), temp.end());
    auto sz = words;
    sort(sz.begin(), sz.end(), [](string& a, string& b) {return a.size() < b.size();});
    string ans;
    for (int i : {0, 1}) {
        for (int j : {m - 2, m - 1}) {
            string f = sz[i] + sz[j];
            string g = sz[j] + sz[i];
            auto match = [&](string& s) {
                vector<string> all;
                for (int i = 1; i < n; i++) {
                    all.push_back(s.substr(0, i));
                    all.push_back(s.substr(n - i, i));
                }
                sort(all.begin(), all.end());
                return all == temp;
                };
            if (match(f)) ans = f;
            else if (match(g)) ans = g;
        }
    }
    set<string> pre, suf;
    for (int i = 1; i < n; i++) {
        pre.insert(ans.substr(0, i));
        suf.insert(ans.substr(n - i, i));
    }
    for (auto& s : words) {
        if (pre.count(s)) {
            cout << "P";
            pre.erase(s);
        }
        else if (suf.count(s)) {
            cout << "S";
            suf.erase(s);
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}