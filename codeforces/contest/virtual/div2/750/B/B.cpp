#include <bits/stdc++.h>
using namespace std;

const int N = 62;
vector<long long> p(N);
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int z = count(a.begin(), a.end(), 0);
    int o = count(a.begin(), a.end(), 1);
    long long ans = p[z] * o;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * 2;
    int t; cin >> t;
    while (t--)solve();
}