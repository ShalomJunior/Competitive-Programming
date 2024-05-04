#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
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

vector<int> lis(vector<int> a) {
    int n = a.size();
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int m = b.size();
    vector<int> dp(n);
    fenwick<int> fen(m);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        dp[i] = 1 + fen.query(j - 1);
        fen.add(j, dp[i]);
    }
    return dp;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    sort(b.begin(), b.end());
    auto dp = lis(a);
    int mx = *max_element(dp.begin(), dp.end());
    int j = m - 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] == mx) {
            while (j >= 0 && b[j] >= a[i]) cout << b[j--] << " ";
        }
        cout << a[i] << " ";
    }
    while (j >= 0) cout << b[j--] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}