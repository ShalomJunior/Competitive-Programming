#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
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
    fenwick<int> fen(n);
    for (auto& c : a) {
        cin >> c;
        fen.add(c, 1);
    }
    int add = 0;
    int mn = INF;
    for (int i = n - 1; i >= 0; i--) {
        fen.add(a[i], -1);
        if (mn >= a[i]) {
            add = max(add, fen.query(a[i]));
            mn = a[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}