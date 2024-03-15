#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3, 0);
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

void solve(int t) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int len = 0;
    fenwick<int> fen(n);
    for (int i = 0; i < n; i++) {
        if (i + a[i] < n) {
            int val = a[i] + 1 + fen.query(i - 1);
            fen.add(i + a[i], val);
            len = max(len, val);
        }
    }
    cout << n - len << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve(i + 1);
}
