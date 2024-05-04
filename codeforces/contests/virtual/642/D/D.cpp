#include <bits/stdc++.h>
#define Mine pair<int, int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    auto comp = [](Mine a, Mine b) {
        int len1 = a.S - a.F + 1;
        int len2 = b.S - b.F + 1;
        if (len1 == len2) return a.F < b.F;
        return len1 > len2;
        };
    set<Mine, decltype(comp)> s(comp);
    s.insert({ 0, n - 1 });
    vector<int> ans(n);
    int id = 0;
    while (!s.empty()) {
        id++;
        auto seg = *s.begin();
        s.erase(s.begin());
        int len = seg.S - seg.F + 1;
        int j;
        if (len & 1) j = (seg.F + seg.S) / 2;
        else j = (seg.F + seg.S - 1) / 2;
        ans[j] = id;
        if (j > seg.F) s.insert({ seg.F, j - 1 });
        if (j < seg.S) s.insert({ j + 1, seg.S });
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}