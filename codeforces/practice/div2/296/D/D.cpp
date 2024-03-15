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
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] = max(arr[index], val);
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum = max(sum, arr[index]);
        }
        return sum;
    }
};

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, w;
        cin >> x >> w;
        a.push_back({ x - w, x + w });
    }
    sort(a.begin(), a.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
        });
    vector<int> c;
    for (int i = 0; i < n; i++) {
        c.push_back(a[i].first);
        c.push_back(a[i].second);
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    int m = c.size();
    vector<int> dp(n);
    fenwick<int> fen(m);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(c.begin(), c.end(), a[i].first) - c.begin() + 1;
        dp[i] = max(1 + fen.query(j), i ? dp[i - 1] : 0);
        j = lower_bound(c.begin(), c.end(), a[i].second) - c.begin() + 1;
        fen.add(j, dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
