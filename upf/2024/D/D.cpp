#include<bits/stdc++.h>
using namespace std;


int f(string s, bool rev = false) {
    if (rev) {
        reverse(s.begin(), s.end());
    }
    int n = s.length();
    string temp;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        while (temp.size() >= 3) {
            string p = temp.substr(temp.size() - 3, 3);
            if (p == "AAB" || p == "BAA") {
                ans++;
                int cnt = 3;
                while (cnt--) temp.pop_back();
            }
            else break;
        }
        if (i < n) temp.push_back(s[i]);
    }
    return ans;
}

int g(string s) {
    int ans = 0;
    function<void(string, int)> go = [&](string r, int done) {
        ans = max(ans, done);
        int m = r.size();
        for (int i = 0; i + 2 < m; i++) {
            string p = r.substr(i, 3);
            if (p == "AAB" || p == "BAA") {
                string t = r.substr(0, i) + r.substr(i + 3, m - (i + 3));
                go(t, done + 1);
            }
        }
        };
    go(s, 0);
    return ans;
}

int h(string s) {
    int ans = 0;
    function<void(string, int)> go = [&](string r, int done) {
        ans = max(ans, done);
        int m = r.size();
        for (int i = 2; i + 1 < m; i++) {
            if (r[i] == 'A') continue;
            if (r[i + 1] == 'A' && (i + 2 == m || r[i + 2] == 'B')) {
                if (r[i - 2] == r[i - 1] && r[i - 1] == 'A') {
                    string p = r.substr(i, 3);
                    go(p, done + 1);
                    return;

                }
            }
        }
        };
    return ans;
}

void solve() {
    int n = 12;
    for (int i = 0; i < (1 << 12); i++) {
        string s;
        for (int j = 0; j < 12; j++) {
            s += (i & (1 << j) ? "A" : "B");
        }
        //cerr << "s = " << s << endl;
        int x = max(f(s, false), f(s, true));
        int y = g(s);
        //cerr << x << " " << y << endl;
        if (x != y) {
            cerr << s << endl;
            cerr << x << " " << y << endl;
        }
        //assert(x == y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}