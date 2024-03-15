#include <bits/stdc++.h>
using namespace std;

const int N = 10;
void solve() {
    int n, m;
    cin >> n >> m;
    auto get = [](string s) {
        int cnt = 0;
        while (!s.empty() && s.back() == '0') {
            cnt++;
            s.pop_back();
        }
        return cnt;
        };
    vector<string> a(n);
    vector<vector<int>> mp(N + 1);
    for (auto& s : a) {
        cin >> s;
        mp[get(s)].push_back(s.size());
    }
    for (int i = 0; i < n; i++) {
        for (int j = N; j >= 0; j--) {
            if (!mp[j].empty()) {
                int s = mp[j].back();
                mp[j].pop_back();
                if (s - j > m) {
                    cout << "Sasha" << endl;
                    return;
                }
                mp[0].push_back(s - j);
                break;
            }
        }
        if (i == n - 1) break;
        for (int j = N; j >= 0; j--) {
            if (!mp[j].empty()) {
                int s = mp[j].back();
                mp[j].pop_back();
                for (int k = 0; k <= N; k++) {
                    if (!mp[k].empty()) {
                        int p = mp[k].back();
                        mp[k].pop_back();
                        mp[k].push_back(s + p);
                        break;
                    }
                }
                break;
            }
        }
    }
    int r = -1;
    for (auto& v : mp) {
        if (!v.empty()) {
            r = v[0];
            break;
        }
    }
    assert(r != -1);
    cout << (r > m ? "Sasha" : "Anna") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
