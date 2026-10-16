#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
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

int f(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 3;
    }
    return ans;
}

void solve(sum<int>& g) {
    int l, r;
    cin >> l >> r;
    int ans = g.query(l, l) + g.query(l, r);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(N);
    for (int i = 0; i < N; i++) a[i] = f(i);
    sum g(a);
    int t; cin >> t;
    while (t--)solve(g);
}