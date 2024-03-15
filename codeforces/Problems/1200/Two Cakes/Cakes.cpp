#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int mx = (a + b) / n;
    for (; mx > 0; mx--) {
        if (a / mx + b / mx >= n && min(a, b) >= mx) break;
    }
    cout << mx << endl;
}