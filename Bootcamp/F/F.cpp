#include <bits/stdc++.h>
using namespace std;

void f(int p, int n) {
    for (int i = 0; i < n; i++) {
        cout << ((p == i) ? 'x' : 'o') << " ";
    }
    cout << endl;
}

int main() {
    vector<string> all;
    unordered_map<string, int> m;
    string s;
    while (cin >> s) {
        all.push_back(s);
        if (!m.count(s)) m[s] = (int)m.size();
    }

    int n = (int)m.size();
    for (auto& s : all)f(m[s], n);
}