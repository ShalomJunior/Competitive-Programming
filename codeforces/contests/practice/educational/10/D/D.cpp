#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < (int)arr.size(); index += (index & (-index))) {
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

void solve() {
    int n;
    cin >> n;
    vector<int> all;
    vector<pair<int, int>> a(n);
    for (auto& [l, r] : a) {
        cin >> l >> r;
        all.push_back(l);
        all.push_back(r);
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](const int& i, const int& j) {
        if (a[i].second != a[j].second) return a[i].second < a[j].second;
        return a[i].first < a[j].first;
        });
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int m = all.size();
    fenwick<int> fen(m);
    vector<int> ans(n);
    for (auto& i : p) {
        auto [l, r] = a[i];
        auto x = lower_bound(all.begin(), all.end(), l) - all.begin() + 1;
        ans[i] = fen.rangeQuery(x, m);
        fen.add(x, 1);
    }
    for (auto& c : ans) cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
