#include <bits/stdc++.h>
#define Data unordered_map<int, int>
using namespace std;

void null(Data& a, int k) { if (!a[k])a.erase(k); }

int f(Data& a, Data& b) {
    int ans = 0;
    vector<int> d;
    for (auto& [k, v] : a) {
        int mine = 1 + log10(k);
        int mn = min(v, b[mine]);
        v -= mn; b[mine] -= mn;
        ans += mn;
        if (!v)d.push_back(k);
    }
    for (auto& e : d) a.erase(e);
    return ans;
}

int g(Data& a) {
    int ans = 0;
    Data h;
    for (auto& [k, v] : a) {
        if (v) h[1 + log10(k)] = v;
        if (k != 1) ans += v;
    }
    a = h;
    return ans;
}


void solve() {
    int n; cin >> n;
    Data a, b;
    int k;
    for (int i = 0; i < n; i++) { cin >> k; a[k]++; }

    for (int i = 0; i < n; i++) {
        cin >> k;
        (a.count(k)) ? a[k]-- : b[k]++;
        null(a, k);
    }

    int ans = f(a, b) + f(b, a);
    ans += g(a) + g(b);
    ans += f(a, b) + f(b, a);

    for (auto& [k, v] : a) ans += 2 * v;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}