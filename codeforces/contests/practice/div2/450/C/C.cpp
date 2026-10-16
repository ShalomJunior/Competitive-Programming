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
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    int base = 0;
    map<int, int> mp;
    fenwick<int> fen(n);
    vector<int> cnt(n);
    for (int i = 0, mx = 0; i < n; i++) {
        cnt[i] = fen.rangeQuery(p[i] + 1, n);
        if (i > 0 && cnt[i] == 0) base++;
        else if (cnt[i] == 1) mp[mx]++;
        fen.add(p[i], 1);
        mx = max(mx, p[i]);
    }
    int mx = -1;
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
        int curr = base + mp[p[i]] + (i > 0 && cnt[i] == 0 ? -1 : 0);
        if (i == 0 && i + 1 < n && cnt[i + 1] <= 1) curr--;
        if (curr >= mx) {
            ans = (curr == mx ? min(ans, p[i]) : p[i]);
            mx = curr;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
