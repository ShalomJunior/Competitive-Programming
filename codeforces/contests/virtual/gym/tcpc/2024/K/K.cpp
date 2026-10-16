#include <bits/stdc++.h>
using namespace std;

const int X = 1001;
void add(set<pair<int, int>>& s, int l, int r) {
    auto it = s.lower_bound({ l, -1 });
    if (it != s.begin()) {
        --it;
        if (it->second + 1 < l) ++it;
    }
    while (it != s.end() && it->first - 1 <= r) {
        l = min(l, it->first);
        r = max(r, it->second);
        it = s.erase(it);
    }
    s.insert({ l, r });
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<set<pair<int, int>>> in(X);
    auto cover = [&](int x, int l, int r) {
        auto it = in[x].lower_bound({ l, -1 });
        if (it != in[x].begin()) {
            --it;
            if (it->first <= l && it->second >= r) return true;
            it++;
        }
        if (it != in[x].end() && it->first <= l && it->second >= r) return true;
        return false;
        };
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            int x;
            cin >> x;
            add(in[x], l, r);
        }
        else if (t == 2) {
            int ans = 0;
            for (int x = 1; x < X; ++x) {
                if (cover(x, l, r)) ans++;
            }
            cout << ans << endl;
        }
        else {
            assert(false);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}