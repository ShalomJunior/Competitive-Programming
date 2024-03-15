#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    unordered_map<char, int> mp;
    for (auto& c : s)mp[c]++;
    int odd = 0;
    for (auto& [k, v] : mp)
        if (v & 1) odd++;

    if (odd > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int n = s.size();
    int l = 0, r = n - 1;
    vector<char> ans(n);
    for (auto& [k, v] : mp) {
        if (v & 1) {
            ans[n / 2] = k;
            v--;
        }
        while (v > 0) {
            ans[l++] = k;
            ans[r--] = k;
            v -= 2;
        }
    }

    for (auto& c : ans)cout << c;
    cout << endl;
}