#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> vs;
    string s;
    unordered_map<string, int> mp;
    while (cin >> s) {
        vs.push_back(s);
        if (mp.find(s) == mp.end()) mp[s] = mp.size();
    }

    for (auto& s : vs) {
        int pos = mp[s];
        for (int j = 0; j < (int)mp.size(); j++) {
            cout << ((j == pos) ? 'x' : 'o') << " ";
        }
        cout << endl;
    }
}