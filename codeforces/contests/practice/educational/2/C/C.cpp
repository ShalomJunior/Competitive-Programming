#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<int> cnt(N);
    for (auto& c : s) cnt[c - 'a']++;
    deque<int> mis;
    for (int i = 0; i < N; i++) {
        if (cnt[i] & 1) mis.push_back(i);
    }
    while (mis.size() > 1) {
        int i = mis.front();
        int j = mis.back();
        mis.pop_front();
        mis.pop_back();
        cnt[i]++;
        cnt[j]--;
    }
    vector<char> ans(n, '-');
    int l = 0, r = n - 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j + 2 <= cnt[i]; j += 2) {
            ans[l] = ans[r] = char('a' + i);
            l++, r--;
        }
    }
    for (auto& c : ans) {
        cout << (c == '-' ? char('a' + mis.front()) : c);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
