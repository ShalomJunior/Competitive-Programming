#include <bits/stdc++.h>
using namespace std;

const int N = 4e5;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < (int)arr.size(); index += (index & (-index))) {
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

fenwick<int> fen(N);
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    map<int, int> h;
    for (auto& [l, r] : p) {
        cin >> l >> r;
        if (l == r) h[l]++;
    }
    for (auto& [k, v] : h) fen.add(k, 1);
    for (auto& [l, r] : p) {
        if (l == r) {
            cout << (h[l] > 1 ? 0 : 1);
        }
        else {
            int cnt = fen.rangeQuery(l, r);
            cout << (cnt < r - l + 1 ? 1 : 0);
        }
    }
    cout << endl;
    for (auto& [k, v] : h) fen.add(k, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}