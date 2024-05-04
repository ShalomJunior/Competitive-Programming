#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;

template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] += val;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int go(map<int, map<int, int>>& mp) {
    int n = mp.size();
    int ans = 0;
    int couple = 0;
    int sum = 0;
    int i = n - 1;
    map<int, int> past, same, diff;
    int tot_same = 0;
    for (auto it = prev(mp.end()); ; it--) {
        auto& h = it->second;
        int cnt = 0;
        for (auto& [k, v] : h) {
            cnt += v;
            same[k] += v * past[k];
            tot_same += v * past[k];
            diff[k] += (sum - past[k]) * v;
            past[k] += v;
        }
        ans += cnt * couple;
        couple += cnt * sum;
        sum += cnt;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    map<int, map<int, int>> f, g;
    for (auto& [x, y] : a) {
        cin >> x >> y;
        f[x][y]++;
        g[y][x]++;
    }
    int ans = go(f) + go(g);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}