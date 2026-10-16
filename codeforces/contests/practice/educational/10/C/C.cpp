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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    fenwick<int> fen(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fen.add(i, a[i]);
    }
    auto check = [&](int len) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int cnt = fen.rangeQuery(i, i + len - 1);
            if (cnt + k >= len) return true;
        }
        return false;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L << endl;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (i + L - 1 <= n && fen.rangeQuery(i, i + L - 1) + k >= L) flag = true;
        if (a[i]) {
            cout << a[i] << " ";
        }
        else {
            if (flag && k) {
                cout << 1 << " ";
                k--;
            }
            else cout << 0 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
