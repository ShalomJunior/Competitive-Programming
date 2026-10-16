#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 26;
const int M = 12;
vector<int> f(M, 1);
void solve() {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> cnt;
    for (auto& c : s) cnt[c]++;
    int den = 1;
    int x = 0, y = 0;
    for (auto& [k, v] : cnt) den *= f[v];
    for (int i = 0; i < n; i++) {
        cnt[s[i]]--;
        for (int j = 0; j < n; j++) {
            cnt[s[j]]++;
            int z = 1;
            for (auto& [k, v] : cnt) z *= f[v];
            if (z >= den) {
                den = z;
                x = i;
                y = j;
            }
            cnt[s[j]]--;
        }
        cnt[s[i]]++;
    }
    s[x] = s[y];
    cout << s << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < M; i++) f[i] = f[i - 1] * i;
    int t; cin >> t;
    while (t--)solve();
}