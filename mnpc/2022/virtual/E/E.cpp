#include <bits/stdc++.h>
using namespace std;

template<typename T>
const T Max(const T& a, const T& b) {
    return max(a, b);
}

template<typename T>
const T Min(const T& a, const T& b) {
    return min(a, b);
}

template<typename T, const T(*op)(const T&, const T&)>
class sparseTable {
public:
    vector<vector<T>> st;
    sparseTable(vector<T> vals) {
        int n = vals.size();
        int rows = __lg(n) + 1;
        st.resize(rows);
        st[0] = vals;
        for (int j = 1; j < rows; j++) {
            st[j].resize(n);
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = __lg(r - l + 1);
        return op(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sparseTable<int, Min> f(a);
    sparseTable<int, Max> g(a);
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        int L = i, R = n - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            int m = f.query(i, mid);
            int M = g.query(i, mid);
            if (M - m > k) {
                R = mid - 1;
            }
            else {
                if (L == mid) g.query(i, R) - f.query(i, R) > k ? R = L : L = R;
                else L = mid;
            }
        }
        ans = max(ans, L - i + 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}