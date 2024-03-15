#include <bits/stdc++.h>
using namespace std;

const int N = 64;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    vector<int> pos;
    for (int i = 0; i < N; i++) {
        if (__builtin_popcount(i) == k)pos.push_back(i);
    }
    int m = pos.size();
    for (int i = 0; i < m; i++) {
        vector<int> use;
        for (int j = 0; j < N; j++) {
            if ((j & a[i]) == a[i])use.push_back(j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(7);
    for (int i = 0; i < 64; i++) {
        a[__builtin_popcount(i)]++;
    }
    for (int i = 0; i < 7; i++) {
        cout << i << " -> " << a[i] << endl;
    }
    int t; cin >> t;
    while (t--) solve();
}