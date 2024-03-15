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
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c, ++c;
    int M = *max_element(a.begin(), a.end());
    fenwick<int> fen(M);
    vector<int> h(M + 1);
    vector<vector<int>> id(M + 1, vector<int>());
    for (int i = 0; i < n; i++) {
        if (!h[a[i]]) fen.add(a[i], 1);
        h[a[i]]++;
        id[a[i]].push_back(i);
    }
    int start = 0;
    vector<int> b;
    while (start < n) {
        int L = 1, R = M + 1;
        while (L < R) {
            int mid = (L + R) / 2;
            fen.query(mid) < mid ? R = mid : L = mid + 1;
        }
        int j = start + 1;
        for (int i = 1; i < L; i++) {
            j = max(j, 1 + *lower_bound(id[i].begin(), id[i].end(), start));
        }
        for (int i = 1; i < L; i++) {
            int del = lower_bound(id[i].begin(), id[i].end(), j) - lower_bound(id[i].begin(), id[i].end(), start);
            h[i] -= del;
            if (!h[i]) fen.add(i, -1);
        }
        b.push_back(L - 1);
        start = j;
    }
    cout << b.size() << endl;
    for (auto& c : b) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}