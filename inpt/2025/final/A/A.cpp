#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int k, x, n;
    cin >> k >> x >> n;
    int K = 1 << k;
    vector<bool> seen(K);
    vector<int> o;
    while (!seen[x]) {
        o.push_back(x);
        seen[x] = true;
        x = (x + __builtin_popcountll(x)) % K;
    }
    int m = o.size();
    int cnt = n * (n + 1) / 2;
    if (cnt < m) {
        cout << o[cnt] << endl;
        return;
    }
    cnt -= m - 1;
    int j = 0;
    while (o[j] != x) j++;
    int len = m - j;
    cnt %= len;
    cout << (cnt == 0 ? o.back() : o[j + cnt - 1]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*
#include<bits/stdc++.h>
#define int long long
using namespace std;

int brute(int k, int x, int n) {
    int K = 1 << k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            x = (x + __builtin_popcountll(x)) % K;
        }
    }
    cout << "x = " << x << endl;
    return x;
}

void solve() {
    int k, x, n;
    cin >> k >> x >> n;
    cout << brute(k, x, n) << endl;
    int K = 1 << k;
    vector<bool> seen(K);
    vector<int> o;
    while (!seen[x]) {
        o.push_back(x);
        seen[x] = true;
        x = (x + __builtin_popcountll(x)) % K;
    }
    int m = o.size();
    int cnt = n * (n + 1) / 2;
    if (cnt < m) {
        cout << o[cnt] << endl;
        return;
    }
    cnt -= m - 1;
    int j = 0;
    while (o[j] != x) j++;
    int len = m - j;
    cnt %= len;
    cout << (cnt == 0 ? o.back() : o[j + cnt - 1]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
*/