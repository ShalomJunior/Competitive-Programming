#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7 + 5;
bitset<N> is_prime;

vector<int> prime;
void compute() {
    for (int i = 2; i < N; i++)is_prime.set(i);

    for (int i = 2; i * i <= N; i++) {
        if (!is_prime[i])continue;
        prime.push_back(i);
        for (int j = i * i; j < N; j += i)is_prime.reset(j);
    }
}

void decompose(int n, unordered_map<int, int>& div) {
    int i = 0;
    while (n) {
        if (is_prime[n]) {
            div[n]++;
            break;
        }
        if (n % prime[i])i++;
        else {
            n /= prime[i];
            div[prime[i]]++;
        }
    }
}

void solve() {
    int n; cin >> n;
    unordered_map<int, int> div;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        decompose(a, div);
    }

    int ans = 0, add = 0;
    for (auto& [k, v] : div) {
        ans += v / 2;
        add += (v & 1);
    }
    ans += add / 3;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    compute();
    int t; cin >> t;
    while (t--)solve();
}