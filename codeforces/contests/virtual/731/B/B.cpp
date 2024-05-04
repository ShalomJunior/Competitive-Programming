#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    deque<char> dq;
    for (auto& c : s) dq.push_back(c);
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        char c = 'a' + i;
        if (dq.front() == c) dq.pop_front();
        else if (dq.back() == c) dq.pop_back();
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}