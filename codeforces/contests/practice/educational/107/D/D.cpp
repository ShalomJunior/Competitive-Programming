#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int cost(string s) {
    int n = s.length();
    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j + 1 < n; j++) {
            if (s[i] == s[j] && s[i + 1] == s[j + 1]) {
                //cerr << i << " " << j << endl;
                r++;
            }
        }
    }
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string>p;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            string r;
            r += char('a' + i);
            r += char('a' + j);
            p.push_back(r);
        }
    }
    string ans = "aa";
    map<string, int> h;
    h[ans]++;
    while (ans.size() < n) {
        int cost = INF;
        string t;
        string z;
        z += ans.back();
        for (auto& r : p) {
            z += r[0];
            int x = h[r] + h[z];
            if (x < cost) {
                cerr << "x = " << x << " " << r << endl;
                cost = x;
                t = r;
            }
            z.pop_back();
        }
        ans += t;
        z += t[0];
        h[t]++;
        h[z]++;
    }
    cout << ans.substr(0, n) << endl;
    cout << "cost = " << cost(ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
