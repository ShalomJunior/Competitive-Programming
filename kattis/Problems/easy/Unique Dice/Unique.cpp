#include <bits/stdc++.h>
#define pr pair<string, int>

using namespace std;

string read() {
    string s;
    for (int i = 0; i < 6; i++) {
        char c; cin >> c;
        s += c;
    }
    sort(s.begin(), s.end());
    return s;
}

bool compare(pr a, pr b) {
    return a.second > b.second;
}

int main() {
    int n; cin >> n;
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++) {
        mp[read()]++;
    }

    auto p = *max_element(mp.begin(), mp.end(), compare);
    cout << p.second << endl;
}