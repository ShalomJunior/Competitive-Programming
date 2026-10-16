#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 31;
vector<int> m(N + 1);

vector<int> g(int n) {
    vector<int> r;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            r.push_back(i);
            if (i != n / i) r.push_back(n / i);
        }
    }
    return r;
}

int get(int r, int k) {
    deque<int> dq;
    for (int j = N; j >= 0; j--) {
        if (k & m[j]) {
            dq.push_back(j);
        }
    }
    int k = N;
    while (k >= 0 && (r & m[k]) == 0) k--;
    int res = 0;
    for (int j = k; j >= 0; j--) {
        if (r & m[j]) {
            while (!dq.empty() && dq.front() > j) dq.pop_front();
            bool flag = false;
            if (!dq.empty() && dq.front() == j) {
                flag = true;
                dq.pop_front();
            }
            if (flag)
                res += get(r - m[j], k);
            res += m[dq.size()] - 1;
        }
    }
    return res;
}

int query(int l, int r, int k) {
    int res = get()
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    int ans = 0;
    vector<int> a = g(n);

    for (auto& d : a) {
        int k = __builtin_popcount(d);
        int curr = pow(3, k);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    m[0] = 1;
    for (int i = 1; i <= N; i++) m[i] = m[i - 1] * 2;
    solve();
}
