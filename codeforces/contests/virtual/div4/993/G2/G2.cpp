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
        int len = R - L + 1;
        int l = L + len / 3;
        int r = R - len / 3;
        int s = ask(l, r);
        if (s == l * r) L = r + 1;
        else if (s == (l + 1) * (r + 1)) R = l;
        else {
            L = l + 1;
            R = r;
        }
    }
    cout << "! " << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}