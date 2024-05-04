#include <bits/stdc++.h>
#define int long long
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
    int n, c; cin >> n >> c;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = a[i].F + i + 1;
        a[i].F += (i < (n + 1) / 2 ? i + 1 : n - i);
    }
    sort(a.begin(), a.end());
    fenwick<int> fen(n);
    for (int i = 0; i < n; i++) {
        fen.add(i + 1, a[i].F);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        fen.add(i + 1, -a[i].F);
        int L = 1, R = n;
        while (L <= R) {
            int mid = (L + R) / 2;
            int q = fen.query(mid);
            if (q <= c - a[i].S) {
                if (L == mid) break;
                else L = mid;
            }
            else R = mid - 1;
        }
        if (L <= R && fen.query(L) <= c - a[i].S) {
            if (L != R && fen.query(R) <= c - a[i].S) L = R;
            ans = max(ans, L + (L < i + 1 ? 1 : 0));
        }
        else if (L > R && c - a[i].S >= 0) {
            ans = max(ans, 1LL);
        }
        fen.add(i + 1, a[i].F);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}