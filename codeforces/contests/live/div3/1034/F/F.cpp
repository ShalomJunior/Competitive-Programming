#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
}


void solve() {
    int n;
    cin >> n;
    set<int> in;
    vector<int> p(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = (n / i) * i; j > 0; j -= i) {
            if (!in.count(j)) {
                p[i] = j;
                p[j] = i;
                in.insert(j);
                in.insert(j);
                break;
            }
        }
    }
    // int u = (n + 1) / 2;
    // for (int mid : {u, u + 1}) {
    //     bool flag = false;
    //     for (int i = 1; i <= n; i++) {
    //         if (i != mid && __gcd(p[i], mid) > 1 && __gcd(p[mid], i) > 1) {
    //             swap(p[i], p[mid]);
    //             flag = true;
    //             break;
    //         }
    //     }
    // }

    for (int i = 1; i <= n;i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
