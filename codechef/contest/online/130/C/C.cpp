#include <bits/stdc++.h>
using namespace std;

int get(string s, string p) {
    int n = s.length();
    string r;
    while (r.size() < n) r += p;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt & 1) {
            s[i] = s[i] == '1' ? '0' : '1';
        }
        if (s[i] != r[i]) {
            cnt++;
        }
    }
    return cnt;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << min(get(s, "01"), get(s, "10")) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}