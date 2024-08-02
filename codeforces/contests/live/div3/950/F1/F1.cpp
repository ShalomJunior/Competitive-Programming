#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3, INF);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] = min(arr[index], val);
        }
    }
    T query(int index) {
        T sum = INF;
        for (; index > 0; index -= (index & (-index))) {
            sum = min(sum, arr[index]);
        }
        return sum;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(k);
    map<int, set<int>> mp;
    vector<int> all;
    for (auto& [l, r] : a) {
        cin >> l >> r;
        --l;
        --r;
        mp[l].insert(r);
        all.push_back(l);
    }
    auto b = a;
    sort(b.begin(), b.end());
    int ans = 0;
    int r = n;
    int mx = m;
    while (!b.empty()) {
        int id = b.back().first;
        ans += (r - id - 1) * mx;
        r = id;
        while (!b.empty() && b.back().first == id) {
            mx = min(mx, b.back().second);
            b.pop_back();
        }
        ans += mx;
    }
    ans += r * mx;
    cout << ans << endl;
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    reverse(all.begin(), all.end());
    int z = all.size();
    map<int, int> h;
    for (int i = 0; i < z; i++) {
        h[all[i]] = i + 1;
    }
    fenwick<int> fen(z);
    for (auto& [l, r] : a) {
        fen.add(h[l], r);
    }
    for (auto& [l, r] : a) {
        if (*mp[l].begin() < r) {
            cout << 0 << " ";
        }
        else {
            if (l + 1 == n) {
                cout << 1 << " ";
            }
            else {
                int p = h[l];
                cout << (fen.query(p - 1) > r ? 1 : 0) << " ";
            }
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}