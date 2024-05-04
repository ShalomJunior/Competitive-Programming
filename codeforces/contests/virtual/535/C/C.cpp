#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int go(string& s, string p) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != p[i % 3]) ans++;
    }
    return ans;
}

void solve() {
    int n; string s;
    cin >> n >> s;
    int bad = INF;
    string pattern;
    vector<string> vec = { "RGB", "RBG", "BGR" ,"BRG","GRB", "GBR" };
    for (auto& p : vec) {
        int diff = go(s, p);
        if (diff < bad) {
            pattern = p;
            bad = diff;
        }
    }
    string ans;
    for (int i = 0; i < n / 3; i++) ans += pattern;
    ans += pattern.substr(0, n % 3);
    cout << bad << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}