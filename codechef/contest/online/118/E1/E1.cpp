#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int n; cin >> n;
    int a = 0, b = 0;
    for (int j = N; j >= 0; j--) {
        if (n & (1 << j)) {
            a = (1 << j);
            b = b - a;
        }
    }
    cout << a << " " << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}