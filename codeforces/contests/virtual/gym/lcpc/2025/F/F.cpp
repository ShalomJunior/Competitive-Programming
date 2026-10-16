#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, n;
    cin >> k >> n;
    int r = k % n;
    cout << k - r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

}