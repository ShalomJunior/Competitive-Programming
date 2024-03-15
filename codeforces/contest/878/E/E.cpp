#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3, 100);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] = min(arr[index], val);
        }
    }
    T query(int index) {
        T sum = 100;
        for (; index > 0; index -= (index & (-index))) {
            sum = min(sum, arr[index]);
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void solve() {
    int n = 9;
    vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    fenwick<int> fenw(n);
    for (int i = 0; i < n; i++) {
        fenw.add(i + 1, a[i]);
    }
    cout << fenw.query(3) << endl;
    cout << fenw.query(4) << endl;
    cout << fenw.query(6) << endl;
    cout << fenw.rangeQuery(3, 7) << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}