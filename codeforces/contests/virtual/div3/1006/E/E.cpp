#include <bits/stdc++.h>
using namespace std;

const int L = 500;
const int INF = 1e9;
int f(int n) { return n * (n - 1) / 2; }

void solve() {
    int k;
    cin >> k;
    int lim = L;
    int sx = 0;
    int sy = 0;
    stringstream ss;
    auto go = [&]() {
        assert(lim);
        int j = 1;
        while (j <= lim && j * (j - 1) / 2 <= k) j++;
        j--;
        for (int i = 0; i < j; i++) ss << sx + i << " " << sy << endl;
        k -= j * (j - 1) / 2;
        lim -= j;
        sx += j;
        sy++;
        };
    while (k) go();
    cout << L - lim << endl;
    cout << ss.str() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}