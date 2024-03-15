#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    unordered_map<char, int> left, right;
    for (auto& c : s)
        right[c]++;

    int best = right.size();
    for (int i = 0; i < n; i++) {
        left[s[i]]++;
        right[s[i]]--;
        if (right[s[i]] == 0) right.erase(s[i]);
        int nxt = left.size() + right.size();
        best = max(best, nxt);
    }

    cout << best << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}