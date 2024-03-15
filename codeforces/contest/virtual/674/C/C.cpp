#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<long long> a(N);
void solve() {
    long long n; cin >> n;
    auto it = lower_bound(a.begin(), a.end(), n);
    cout << (it - a.begin()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a[0] = 1;
    for (int i = 1; i < N; i++) {
        int add = i / 2 + i % 2;
        a[i] = 1LL * (1 + add) * (i - add + 1);
    }
    int t; cin >> t;
    while (t--)solve();
}