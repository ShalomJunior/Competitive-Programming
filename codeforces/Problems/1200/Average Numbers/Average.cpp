#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v) cin >> c;
    int sm = accumulate(v.begin(), v.end(), 0);

    int ans = 0; int mod = n - 1;
    stringstream out;
    for (int i = 0; i < n; i++) {
        int nxt = sm - v[i];
        if (nxt % mod == 0 && nxt / mod == v[i]) {
            ans++;
            out << i + 1 << " ";
        }
    }
    cout << ans << endl;
    cout << out.str() << endl;
}