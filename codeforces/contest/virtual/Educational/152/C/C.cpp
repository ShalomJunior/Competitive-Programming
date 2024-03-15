#include <bits/stdc++.h>
using namespace std;

const int N = 50;
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    fenwick<int> fen(n);
    vector<int> last(N + 1, -1);
    vector<vector<int>> dp(q, vector<int>(N + 1));
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (i) dp[i] = dp[i - 1];
        if (last[t] == -1) {
            for (int j = 0; j < n; j++) {
                if (a[j] == t) {
                    int cnt = fen.rangeQuery(j + 1, n);
                    cout << j + 1 + cnt << " ";
                    fen.add(j + 1, 1);
                    break;
                }
            }
        }
        else {
            int cnt = 0;
            for (int j = 1; j <= N; j++) {
                if (dp[i][j] != dp[last[t]][j]) cnt++;
            }
            cout << cnt + 1 << " ";
        }
        dp[i][t]++;
        last[t] = i;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}