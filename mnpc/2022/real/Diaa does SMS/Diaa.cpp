#include <bits/stdc++.h>
#include <cstring>

using namespace std;

pair<string, string> read(char lim = ',') {
    string s; cin >> s;
    int pos = s.find(lim);
    return { s.substr(0, pos), s.substr(pos + 1, s.length()) };
}

int main() {
    int n; cin >> n;
    unordered_map<string, string> h1(n);
    for (int i = 0; i < n; i++) {
        auto in = read();
        h1[in.first] = in.second;
    }

    int m; cin >> m;
    unordered_map<string, string> h2(m);
    for (int i = 0; i < m; i++) {
        auto in = read();
        h2[in.second] = in.first;
    }

    map<string, pair<string, string>> ans;
    for (auto [k, v] : h1) {
        if (h2.find(k) != h2.end()) {
            ans[k] = make_pair(v, h2[k]);
        }
    }

    for (auto [k, v] : ans)
        cout << k << "," << v.first << "," << v.second << endl;

}