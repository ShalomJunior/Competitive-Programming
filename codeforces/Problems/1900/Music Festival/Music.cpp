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
    vector<vector<int>> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int v; cin >> v;
            if (!a[i].empty() && a[i].back() >= v)continue;
            a[i].push_back(v);
            b.push_back(v);
        }
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 0; i < n; i++) {
        for (auto& idx : a[i]) {
            idx = lower_bound(b.begin(), b.end(), idx) - b.begin() + 1;
        }
    }
    sort(a.begin(), a.end(), [&](const vector<int>& p, const vector<int>& q) {
        return p.back() < q.back(); }
    );
    int m = b.size(), ans = 0;
    fenwick<int> fenw(m);
    for (auto& v : a) {
        int curr = 0;
        int k = v.size();
        for (int i = 0; i < k; i++) {
            curr = max(curr, k - i + fenw.query(v[i] - 1));
        }
        ans = max(ans, curr);
        fenw.add(v.back(), curr);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}