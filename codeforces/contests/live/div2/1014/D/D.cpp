#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const string S = "ILT";
void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n < 2) {
        cout << -1 << endl;
        return;
    }
    int i = count(s.begin(), s.end(), 'I');
    int l = count(s.begin(), s.end(), 'L');
    int t = count(s.begin(), s.end(), 'T');
    set<pair<int, char>> o;
    o.insert({ i, 'I' });
    o.insert({ l, 'L' });
    o.insert({ t, 'T' });
    int moves = 2 * n;
    stringstream ss;
    while (o.begin()->first < prev(o.end())->first) {
        if (moves == 0) {
            cout << -1 << endl;
            return;
        }
        moves--;
        auto p = *o.begin();
        char c = p.second;
        o.erase(o.begin());
        int m = s.size();
        bool f = false;
        for (int i = 0; i + 1 < m; i++) {
            if (s[i] != s[i + 1] && s[i] != c && s[i + 1] != c) {
                ss << i + 1 << endl;
                s = s.substr(0, i + 1) + c + s.substr(i + 1, m - i - 1);
                f = true;
                break;
            }
        }
        if (!f) {
            cout << -1 << endl;
            return;
        }
        p.first++;
        o.insert(p);
    }
    cout << 2 * n - moves << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
