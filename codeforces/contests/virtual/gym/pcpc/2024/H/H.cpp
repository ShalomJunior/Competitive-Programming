#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;

const int M = 30;
const int N = 1e6 + 5;
bitset<N> prime;
vector<int> m(M);
vector<vector<int>> D(N);
vector<long long> ans(N);

void init() {
    m[0] = 1;
    for (int i = 1; i < M; i++) m[i] = m[i - 1] * 2;
    for (int i = 2; i < N; i++) prime.set(i);
    vector<int> in(N);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            D[j].push_back(i);
            if (prime[i]) {
                if (j > i) prime.reset(j);
                in[j]++;
            }
        }
    }
    in[1]++;
    auto f = [&](int x) {
        return  x == 0 ? 0 : m[x - 1];
        };
    for (int x = 1; x < N; x++) {
        for (auto g : D[x]) {
            int s = x / g;
            if (g > s) break;
            ans[x] += f(in[s - 1]);
            if (g != s) {
                ans[x] += f(in[g - 1]);
            }
        }
    }
}

void solve() {
    int x;
    cin >> x;
    cout << ans[x] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--) solve();
}
