#include <bits/stdc++.h>

using namespace std;

void out(int v, int times) {
    for (int i = 0; i < times; i++)
        cout << v << " ";
}

void solve() {
    int n, s, r; cin >> n >> s >> r;

    int mean = r / (n - 1);
    int up = r % (n - 1);

    cout << s - r << " ";
    if (r % (n - 1) == 0)
        out(mean, n - 1);
    else {
        out(1 + mean, up);
        out(mean, n - 1 - up);
    }
    cout << endl;
}
int main() {
    int t; cin >> t;
    while (t--)solve();
}