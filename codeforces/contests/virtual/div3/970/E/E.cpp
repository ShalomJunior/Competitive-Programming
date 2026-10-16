#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int INF = 1e9;
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
    int n;
    string s;
    cin >> n >> s;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c1 = 'a' + i;
            char c2 = 'a' + j;
            vector<int> x(n);
            vector<int> y(n);
            for (int k = 0; k < n; k++) {
                if (k & 1) {
                    x[k] = s[k] != c2;
                    y[k] = s[k] != c1;
                }
                else {
                    x[k] = s[k] != c1;
                    y[k] = s[k] != c2;
                }
            }
            sum f(x);
            sum g(y);
            if (n % 2 == 0)
                ans = min(ans, f.query(0, n - 1));
            for (int k = 0; k < n && n % 2; k++) {
                int cnt = 1;
                if (k > 0) {
                    cnt += f.query(0, k - 1);
                }
                if (k < n - 1) {
                    if (k & 1) {
                        cnt += g.query(k + 1, n - 1);
                    }
                    else {
                        cnt += f.query(k + 1, n - 1);
                    }
                }
                ans = min(ans, cnt);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}