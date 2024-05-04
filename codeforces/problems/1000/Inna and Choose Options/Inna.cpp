#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();

    int cnt = 0;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) continue;

        bool b = false;
        for (int j = 0; j < i; j++) {
            bool temp = true;
            char last = s[j];
            for (int k = j; k < n; k += i) {
                temp &= (last == s[k] && s[k] == 'X');
            }
            b |= temp;
        }

        if (b) {
            cnt++;
            ans.push_back(make_pair(n / i, i));
        }

    }
    sort(ans.begin(), ans.end());
    cout << cnt << " ";
    for (auto& p : ans) {
        cout << p.first << "x" << p.second << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}