#include <bits/stdc++.h>
#define int long long
using namespace std;

struct info {
    int a;
    int b;
    int c;
};

void solve() {
    int n;
    cin >> n;
    vector<info> p(n);
    vector<int> s;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        p[i] = { a, b, c };
        s.push_back(a + b + c - max({ a, b, c }) + 2);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        auto [a, b, c] = p[i];
        int tot = a + b + c;
        auto it = upper_bound(s.begin(), s.end(), tot);
        int j = 0;
        if (it != s.begin()) {
            j = it - s.begin();
        }
        if (max({ a, b, c }) >= 2) j--;
        cout << j << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}