#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
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
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int ans = 0;
    fenwick<int> cnt(N), fen(N);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        int add = cnt.rangeQuery(j + 1, N);
        fen.add(j, add);
        ans += fen.rangeQuery(j + 1, N);
        cnt.add(j, 1);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}