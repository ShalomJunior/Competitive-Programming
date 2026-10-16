#include <bits/stdc++.h>
using namespace std;

const int N = 26;

auto get(string s) {
    int n = s.length();
    map<char, vector<int>> h;
    for (int i = 0; i < n; i++) h[s[i]].push_back(i);
    vector<vector<int>> ans;
    for (auto& [k, v] : h) ans.push_back(v);
    sort(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int m;
    cin >> m;
    vector<string> s(m);
    for (auto& c : s) cin >> c;
    int z = set<int>(a.begin(), a.end()).size();
    if (z > N) {
        cout << "NO" << endl;
        return;
    }
    map<int, vector<int>> h;
    for (int i = 0; i < n; i++) h[a[i]].push_back(i);
    vector<vector<int>> o;
    for (auto& [k, v] : h) o.push_back(v);
    sort(o.begin(), o.end());
    for (auto& str : s) {
        int k = str.length();
        if (k == n) {
            cout << (get(str) == o ? "YES" : "NO") << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
