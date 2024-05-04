#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> vec;

void prepare() {
    for (int i = 1; i < N; i += 4) {
        vec.push_back(i);
    }
}

void solve() {
    int n; cin >> n;
    int i, alice = 0, bob = 0, sum = 0;
    for (i = 0; i < vec.size() && sum + vec[i] <= n; i++) {
        if (i & 1)bob += vec[i];
        else alice += vec[i];
        sum += vec[i];
    }
    if (i & 1)bob += (n - sum);
    else alice += (n - sum);
    cout << alice << " " << bob << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}