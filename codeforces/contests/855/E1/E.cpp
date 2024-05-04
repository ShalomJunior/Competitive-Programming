#include <bits/stdc++.h>

using namespace std;

bool anag(string s1, string s2) {
    int n = s1.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s1[i]]++;
        mp[s2[i]]--;
    }

    for (auto& [k, v] : mp) {
        if (v != 0)return false;
    }
    return true;
}

void solve() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    if (!anag(s, t)) {
        cout << "NO" << endl;
        return;
    }

    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) pos.push_back(i);
    }

    int m = pos.size();
    if (m > 0) {
        for (int i = 0; i < pos.size() - 1; i++) {
            int diff = pos[i + 1] - pos[i];

            bool b = diff > k + 1;
            int left = pos[i], right = n - 1 - pos[i];

            if (diff < k) {
                b |= (left + right <= k);
                b |= (left < k && right < k);
            }
            if (b) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}