#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b) {
    cout << "?  " << a << " " << b << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int L = 2, R = 1000;
    while (L < R) {
        int mid = (L + R) / 2;
        ask(mid, mid) > mid* mid ? R = mid : L = mid + 1;
    }
    cout << "! " << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}