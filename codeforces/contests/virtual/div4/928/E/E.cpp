#include <bits/stdc++.h>
using namespace std;

const int N = 32;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(N);
    a[0] = (n + 1) / 2;
    for (int i = 1; i < N; i++) {
        a[i] = n / (1 << i);
    }
    vector<int> b(N);
    b[0] = a[0];
    b[N - 1] = a[N - 1];
    for (int i = 1; i < N - 1; i++) {
        b[i] = a[i] - a[i + 1];
    }
    int p = 0;
    for (int i = 0; i < N; i++) {
        if (p + b[i] < k) p += b[i];
        else {
            int j = k - p;
            cout << (1 << i) * (1 + (j - 1) * 2) << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}