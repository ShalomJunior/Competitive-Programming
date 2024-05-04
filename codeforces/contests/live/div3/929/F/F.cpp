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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (auto& [f, s] : a) cin >> f >> s;
    multiset<int> state;
    sort(a.begin(), a.end());
    vector<int> R(n + 1), cnt(n + 1);
    for (int i = 1, k = 0; i <= n; i++) {
        state.erase(i - 1);
        while (k < m && a[k].first == i) {
            state.insert(a[k].second);
            k++;
        }
        cnt[i] = state.size();
        R[i] = state.empty() ? -1 : *prev(state.end());
    }
    fenwick<int> fen(n + 3);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = fen.query(i - 1) + cnt[i];
        if (R[i] != -1)
            fen.add(R[i], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}