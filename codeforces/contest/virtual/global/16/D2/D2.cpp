#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first 
#define S second
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    map<int, int> cnt;
    for (auto& c : a) {
        cin >> c;
        cnt[c]++;
    }
    auto get = [&](int k) {
        int r = k / m;
        int c = k % m;
        return make_pair(r, c);
        };
    map<int, queue<int>> q;
    int start = 0;
    for (auto& [k, v] : cnt) {
        int s = start, e = start + v - 1;
        auto [rs, cs] = get(s);
        auto [re, ce] = get(e);
        if (rs == re) {
            for (int i = e; i >= s; i--) q[k].push(i);
        }
        else {
            for (int j = m - 1; j >= cs; j--) q[k].push(rs * m + j);
            for (int i = rs + 1; i < re; i++) {
                for (int j = m - 1; j >= 0; j--) q[k].push(i * m + j);
            }
            for (int j = ce; j >= 0; j--) q[k].push(re * m + j);
        }
        start += v;
    }
    vector<fenwick<int>> fen(n, fenwick<int>(m));
    long long ans = 0;
    for (int i = 0; i < n * m; i++) {
        int p = q[a[i]].front();
        q[a[i]].pop();
        auto [r, c] = get(p);
        ans += fen[r].query(c);
        fen[r].add(c + 1, 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
