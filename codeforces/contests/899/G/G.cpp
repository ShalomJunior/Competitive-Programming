#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int cnt = count(s.begin(), s.end(), 'A');
    if (s[0] == 'B' || s.back() == 'B' || s.find("BB") != -1) {
        cout << cnt << endl;
        return;
    }
    vector<int> a;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            if (a.empty()) a.push_back(1);
            else {
                if (s[i - 1] == 'B') a.push_back(1);
                else a.back()++;
            }
        }
    }
    sort(a.begin(), a.end());
    cout << accumulate(a.begin() + 1, a.end(), 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
