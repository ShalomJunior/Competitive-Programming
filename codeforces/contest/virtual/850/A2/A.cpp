#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> vec;

void prepare() {
    for (int i = 1; i < N; i += 4)
        vec.push_back(i);
}

void f(int& w, int& b, int& sum, int& add) {
    w += add / 2;
    b += add / 2;
    if (add & 1) {
        if (sum & 1) b++;
        else w++;
    }
}

void solve() {
    int n; cin >> n;
    int i, a1 = 0, a2 = 0, b1 = 0, b2 = 0, sum = 0;
    for (i = 0; i < vec.size() && sum + vec[i] <= n; i++) {
        if (i & 1) f(b1, b2, sum, vec[i]);
        else f(a1, a2, sum, vec[i]);
        sum += vec[i];
    }
    if (n - sum > 0) {
        int k = n - sum;
        if (i & 1) f(b1, b2, sum, k);
        else f(a1, a2, sum, k);
    }
    cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}