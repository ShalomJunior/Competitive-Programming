#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<string, string> um, rev;
    for (int i = 0; i < n; i++) {
        string e, s; cin >> e >> s;
        um[e] = s;
        rev[s] = e;
    }

    multiset<pair<int, string>> ms;
    for (auto& [k, v] : um) {
        if (um.find(v) != um.end()) ms.insert(mp(0, k));
        else ms.insert(mp(1, k));
    }

    while (!ms.empty()) {
        auto del = prev(ms.end());
        if (del->first) {
            if (rev.find(del->second) != rev.end()) {
                string str = rev[del->second];
                ms.erase(mp(0, str));
                ms.insert(mp(1, str));
            }
            ms.erase(del);
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}