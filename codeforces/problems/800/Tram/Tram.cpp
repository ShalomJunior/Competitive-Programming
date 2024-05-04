#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int mx = INT_MIN, curr = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        curr += (b - a);
        mx = max(mx, curr);
    }

    cout << mx << endl;
}