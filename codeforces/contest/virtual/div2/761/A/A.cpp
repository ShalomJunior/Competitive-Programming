#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    vector<int>p(N);
    iota(p.begin(), p.end(), 0);
    if (t == "abc" && count(s.begin(), s.end(), 'a')) swap(p[1], p[2]);
    sort(s.begin(), s.end(), [&](char a, char b) {
        return p[a - 'a'] < p[b - 'a'];
        });
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}