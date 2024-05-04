#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v;
    unordered_map<int, int>mp;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        c %= 10;
        if (mp[c] < 3) {
            mp[c]++;
            v.push_back(c);
        }
    }

    n = v.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((v[i] + v[j] + v[k]) % 10 == 3) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}