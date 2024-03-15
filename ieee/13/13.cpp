#include <bits/stdc++.h>
using namespace std;

const int N = 7;
void solve() {
    string line; getline(cin, line);
    vector<int> a(N);
    for (auto& c : line) {
        if ('a' <= c && c <= 'g') {
            a[c - 'a']++;
        }
    }
    int M = *max_element(a.begin(), a.end());
    vector<char> ans;
    for (int i = 0; i < N; i++) {
        if (a[i] == M) {
            char c = 'A' + i;
            ans.push_back(c);
        }
    }
    cout << ans[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while (t--) solve();
}