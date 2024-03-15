#include <bits/stdc++.h>

using namespace std;
int cn = 0;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cn += (a & b || a & c || b & c) ? 1 : 0;
}

int main() {
    int n; cin >> n;
    while (n--)solve();
    cout << cn << endl;
}