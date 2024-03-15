#include <bits/stdc++.h>
using namespace std;

void dec(int n, map<int, int>& div) {
    for (int i = 2; i <= 5; i++) {
        while (n % i == 0) div[i]++, n /= i;
    }
}

void solve() {
    int n, kx; cin >> n >> kx;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x]++;
    }
    vector<int> a;
    for (auto& [k, cnt] : h) {
        for (int i = 0; i < min(cnt, 3); i++)
            a.push_back(k);
    }
    map<int, int> d, comp;
    dec(kx, comp);
    auto go = [&]() {
        bool b = true;
        for (auto& [k, cnt] : comp) {
            b &= d[k] >= cnt;
        }
        return b;
        };
    for (auto& c : a) dec(c, d);
    if (go()) { cout << 0 << endl; return; }
    int m = a.size();
    d.clear();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int z = a[j];
            if (j == i) z++;
            dec(z, d);
        }
        if (go()) { cout << 1 << endl; return; }
        d.clear();
    }
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            for (int k = 0; k < m; k++) {
                int z = a[k];
                if (k == i) z++;
                if (k == j) z++;
                dec(z, d);
            }
            if (go()) { cout << 2 << endl; return; }
            d.clear();
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            for (int k = j; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    int z = a[l];
                    if (l == i) z++;
                    if (l == j) z++;
                    if (l == k) z++;
                    dec(z, d);
                }
                if (go()) { cout << 3 << endl; return; }
                d.clear();
            }
        }
    }
    cout << 4 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}