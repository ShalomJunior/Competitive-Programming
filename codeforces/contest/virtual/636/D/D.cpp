#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    fenwick<int> less(2 * k), great(2 * k);
    vector<pair<int, Mine>> vec;
    int sub = 0;
    for (int i = 0; i < n / 2; i++) {
        int sum = a[i] + a[n - 1 - i];
        int m = min(a[i], a[n - 1 - i]);
        int M = max(a[i], a[n - 1 - i]);
        vec.push_back({ sum, {m, M} });
        great.add(m + 1, 1);
        if (M == 1) sub++;
    }
    sort(vec.rbegin(), vec.rend());
    int ans = INF;
    for (int i = 2; i <= 2 * k; i++) {
        int eq = 0, sub = 0;
        while (!vec.empty() && vec.back().F <= i) {
            auto l = vec.back();
            if (l.F == i) eq++;
            great.add(l.S.F + 1, -1);
            if (l.S.S == 1) sub--;
            less.add(l.S.S + k, 1);
            if (l.S.F == k) sub++;
            vec.pop_back();
        }
        int q1 = great.query(i);
        int q2 = less.query(i - 1);
        int curr = q1 + 2 * (vec.size() - q1) + 2 * q2 + (n / 2 - vec.size() - q2) - eq;
        ans = min(ans, curr - sub);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}