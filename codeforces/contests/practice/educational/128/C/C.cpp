#include <bits/stdc++.h>
using namespace std;

template<typename T>
class sum {
public:
    int n;
    vector<T> pref;
    sum(vector<T>& arr) {
        n = arr.size();
        pref.resize(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    T query(int l, int r) {
        assert(l >= 0 && r < n);
        return pref[r] - (l ? pref[l - 1] : 0);
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        s[i] == '0' ? x[i] = 1 : y[i] = 1;
    }
    sum<int> X(x), Y(y);
    auto check = [&](int mid) {
        for (int i = 0; i < n; i++) {
            int cnt = i ? X.pref[i - 1] : 0;
            int o = i ? Y.pref[i - 1] : 0;
            int j = upper_bound(X.pref.begin(), X.pref.end(), cnt + mid) - X.pref.begin();
            if (X.pref.back() > cnt + mid) {
                j--;
                o += Y.query(j + 1, n - 1);
            }
            if (o <= mid) return true;
        }
        return false;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << R << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}