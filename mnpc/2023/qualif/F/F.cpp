#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int N = 60;
const int K = 1e18;
vector<double> fact(N);

vector<int> generate(const vector<int>& arr) {
    int n = arr.size();
    vector<int> ans = { 0 };
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (auto& c : ans) temp.push_back(c + arr[i]);
        vector<int> res;
        merge(
            ans.begin(), ans.end(),
            temp.begin(), temp.end(),
            back_inserter(res)
        );
        res.resize(unique(res.begin(), res.end()) - res.begin());
        ans = res;
    }
    return ans;
}

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> c(n), g(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> g[i];
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        double num = fact[c[i]];
        double den = fact[g[i]] * fact[c[i] - g[i]];
        cnt[i] = ceil(num / den);
    }
    sort(cnt.begin(), cnt.end());
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        i < n / 2 ? a.push_back(cnt[i]) : b.push_back(cnt[i]);
    }
    auto A = generate(a);
    auto B = generate(b);
    int i = 0, j = B.size() - 1;
    while (i < A.size() && j >= 0) {
        if (A[i] + B[j] == s) {
            cout << "done" << endl;
            return;
        }
        else if (A[i] + B[j] < s) i++;
        else j--;
    }
    cout << "deal with it" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1.0;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;
    int t; cin >> t;
    while (t--)solve();
}
