#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

int M;
const int N = 31;
vector<int> go(int n) {
    vector<int> ans; ans.reserve(N);
    for (int i = 1; i < N; i++) {
        int add = (1 << i) * n;
        if (add <= M) ans.push_back(add);
        else break;
    }
    while (n) { ans.push_back(n); n /= 2; }
    return ans;
}

void solve() {
    int n; cin >> n;
    map<int, vector<int>> a_hash;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a_hash[x].push_back(i);
        M = max(M, x);
    }
    map<int, vector<int>> b_gen_hash;
    vector<multiset<int>> matches(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        auto can = go(a);
        for (auto& c : can) {
            if (!a_hash.count(c))continue;
            for (auto& j : a_hash[c]) {
                matches[j].insert(a);
                b_gen_hash[a].push_back(j);
            }
        }
    }
    set<Mine> ords;
    for (int i = 0; i < n; i++) {
        ords.insert({ matches[i].size(), i });
    }
    vector<bool> done(n);
    while (!ords.empty()) {
        auto wk = ords.begin();
        if (!wk->F) { cout << "NO" << endl; return; }
        int i = wk->S;
        ords.erase(ords.begin());
        int pattern = *matches[i].begin();
        for (auto& j : b_gen_hash[pattern]) {
            if (j == i || done[j])continue;
            auto it = matches[j].find(pattern);
            if (it != matches[j].end()) {
                ords.erase({ matches[j].size(), j });
                matches[j].erase(it);
                ords.insert({ matches[j].size(), j });
            }
        }
        done[i] = true;
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}