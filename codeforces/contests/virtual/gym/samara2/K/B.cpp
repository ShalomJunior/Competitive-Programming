#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    map<char, int> h;
    for (auto& c : s) h[c]++;
    deque<int> l, r;
    int i = 0;
    while (i < n && s[i] == s[0]) {
        r.push_front(s[i]);
        h[s[i]]--;
        i++;
    }
    if (i == n) {
        cout << "YES" << endl;
        return;
    }
    l.push_front(s[i]);
    h[s[i]]--;
    i++;
    while (i < n) {
        if (s[i] == s[0]) {
            r.push_front(s[i]);
        }
        else {
            if (s[i] == l.back()) {
                if (h[s[0]] == 0) {
                    r.push_front(s[i]);
                }
                else {
                    l.push_front(s[i]);
                }
            }
            else {
                l.push_front(s[i]);
            }
        }
        h[s[i]]--;
        i++;
    }
    string ans;
    while (!l.empty()) {
        ans += l.front();
        l.pop_front();
    }
    while (!r.empty()) {
        ans += r.front();
        r.pop_front();
    }
    cout << "ans = " << ans << endl;
    int x = 0;
    while (x < n && ans[x] == ans[0]) x++;
    int y = n - 1;
    while (y >= 0 && ans[y] == ans[n - 1]) y--;
    cout << x << " " << y << endl;
    cout << count(s.begin(), s.end(), ans[0]) << endl;
    cout << count(s.begin(), s.end(), ans[n - 1]) << endl;
    if (count(s.begin(), s.end(), ans[0]) != x || count(s.begin(), s.end(), ans[n - 1]) != n - 1 - y) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}