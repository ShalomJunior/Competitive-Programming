#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int k = n; k > 0; k--) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int z = q.size();
            if (z & 1) {
                if (s[i] == '1') {
                    q.push(i + k - 1);
                }
            }
            else {
                if (s[i] == '0') {
                    q.push(i + k - 1);
                }
            }
            while (!q.empty() && q.front() <= i) q.pop();
        }
        if (q.empty()) {
            cout << k << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
