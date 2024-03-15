#include <bits/stdc++.h>
using namespace std;

const int M = 200;
const int N = 500;
const int S = 200;
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
    long long n; cin >> n;
    vector<int> ans;
    vector<long long> dp(M);
    fenwick<long long> fen(N);
    ans.push_back(S);
    dp[0] = 1;
    fen.add(S, 1);
    long long s = 1 + dp[0];
    for (int i = 1, m = S; (n - s) && i < M; i++) {
        long long r = n - s;
        int L = m - 1, R = S + i;
        while (L < R) {
            int mid = (L + R) / 2;
            if (fen.query(mid - 1) + 1 > r) R = mid - 1;
            else {
                if (L == mid) fen.query(R - 1) + 1 > r ? R = L : L = R;
                else L = mid;
            }
        }
        ans.push_back(L);
        m = min(m, L);
        dp[i] = fen.query(L - 1) + 1;
        s += dp[i];
        fen.add(S + i, dp[i]);
    }
    if (n - s > 0) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
