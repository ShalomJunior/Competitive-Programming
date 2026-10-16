#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
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
    for (auto& c : a) cin >> c;
    auto b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int m = b.size();
    fenwick<int> fen(m);
    for (auto& c : a) {
        int j = lower_bound(b.begin(), b.end(), c) - b.begin() + 1;
        fen.add(j, 1);
    }
    int mn = b[0];
    int less = INF;
    for (auto& c : a) {
        int j = lower_bound(b.begin(), b.end(), c) - b.begin() + 1;
        fen.add(j, -1);
        int cnt = fen.rangeQuery(1, j - 1);
        if (c != mn) {
            if (less < c || cnt >0) {
                c++;
                less = min(less, c);
            }
        }
    }
    sort(a.begin(), a.end());
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}