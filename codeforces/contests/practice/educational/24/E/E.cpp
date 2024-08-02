#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
class sum {
public:
    int n;
    vector<T> pref;
    sum(vector<T>& arr) {
        n = arr.size();
        pref.resize(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    T query(int l, int r) {
        assert(l >= 0 && r < n);
        return pref[r] - (l ? pref[l - 1] : 0);
    }
};

const int N = 5e6;
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

void dec(int n, map<int, int>& div) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            div[n]++;
            return;
        }
        while (n % primes[i] == 0) {
            div[primes[i]]++;
            n /= primes[i];
        }
        i++;
    }
    if (n > 1) div[n]++;
}

int get(int n, int d) {
    int cnt = 0;
    while (n % d == 0) {
        cnt++;
        n /= d;
    }
    return cnt;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    map<int, int> ps;
    dec(k, ps);
    map<int, int> h;
    vector<sum<int>> all;
    for (auto& [k, v] : ps) {
        vector<int> b(n);
        for (int i = 0; i < n; i++) b[i] = get(a[i], k);
        h[k] = h.size();
        all.push_back(sum(b));
    }
    int ans = 0;
    auto check = [&](int l, int r) {
        for (auto& [k, v] : ps) {
            if (all[h[k]].query(l, r) < v) {
                return false;
            }
        }
        return true;
        };
    for (int i = 0; i < n; i++) {
        int L = i, R = n - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            check(i, mid) ? R = mid : L = mid + 1;
        }
        if (check(i, R)) ans += n - R;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    solve();
}
