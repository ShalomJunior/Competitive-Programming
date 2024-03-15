#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int L = 26;
const int INF = 1e7;
void solve() {
    int n; string s; cin >> n >> s;
    set<char> in(s.begin(), s.end());
    int diff = in.size();
    vector<pair<int, char>> occ(L);
    for (int i = 0; i < L; i++)occ[i].S = 'a' + i;
    for (auto& c : s) occ[c - 'a'].F++;
    sort(occ.rbegin(), occ.rend());
    int best = INF, choose;
    for (int i = 1; i <= L; i++) {
        if (n % i)continue;
        int k = n / i;
        int ths = 0;
        for (int j = 0; j < i; j++) {
            ths += min(occ[j].F, k);
        }
        if (n - ths < best) {
            choose = i;
            best = n - ths;
        }
    }
    int k = n / choose;
    map<char, int> del, add;
    for (int i = 0; i < L; i++) {
        auto p = occ[i];
        if (i < min(choose, diff)) {
            if (p.F > k) del[p.S] = p.F - k;
            if (p.F < k) add[p.S] = k - p.F;
        }
        else { if (p.F) del[p.S] = p.F; }
    }
    if (choose > diff) {
        int plus = choose - diff;
        for (int i = 0; i < L && plus; i++) {
            if (!in.count('a' + i)) {
                add['a' + i] = k;
                plus--;
            }
        }
    }
    string ans = s;
    for (auto& c : ans) {
        if (del.count(c)) {
            del[c]--;
            if (!del[c]) del.erase(c);
            auto pt = add.begin();
            c = pt->F; pt->S--;
            if (!pt->S)add.erase(pt);
        }
    }
    cout << best << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}