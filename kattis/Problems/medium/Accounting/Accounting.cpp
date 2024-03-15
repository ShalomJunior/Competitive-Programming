#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; cin >> n >> q;

    unordered_map<int, int> mp;
    int be = 0;
    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        if (s == "PRINT") {
            int j; cin >> j;
            if (mp.find(j) != mp.end())
                cout << mp[j] << endl;
            else cout << be << endl;
        }
        else if (s == "SET") {
            int j, x; cin >> j >> x;
            mp[j] = x;
        }
        else if (s == "RESTART") {
            int x; cin >> x;
            mp.clear();
            be = x;
        }
    }
}