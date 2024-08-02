#include <bits/stdc++.h>
#define int long long
using namespace std;

string int128_to_string(__int128 value) {
    if (value == 0)
        return "0";

    bool neg = false;
    if (value < 0) {
        neg = true;
        value = -value;
    }

    string ans;
    while (value > 0) {
        ans = static_cast<char>('0' + value % 10) + ans;
        value /= 10;
    }

    if (neg) {
        ans = '-' + ans;
    }

    return ans;
}

std::ostream& operator<<(std::ostream& os, __int128 value) {
    os << int128_to_string(value);
    return os;
}

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
    int N = b.size() + 3;
    fenwick<__int128_t> fen(N);
    fenwick<__int128_t> cnt(N);
    __int128_t ans = 0;
    for (int j = 0; j < n; j++) {
        int l = upper_bound(b.begin(), b.end(), a[j] - 2) - b.begin() + 1;
        if (l > 1) {
            l--;
            ans += cnt.query(l) * a[j];
            ans -= fen.query(l);
        }
        int r = lower_bound(b.begin(), b.end(), a[j] + 2) - b.begin() + 1;
        ans += cnt.rangeQuery(r, N) * a[j];
        ans -= fen.rangeQuery(r, N);
        int p = lower_bound(b.begin(), b.end(), a[j]) - b.begin() + 1;
        fen.add(p, a[j]);
        cnt.add(p, 1);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}