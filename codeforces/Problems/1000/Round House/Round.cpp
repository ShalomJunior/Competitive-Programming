#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = a + b % n;

    if (ans == 0) ans = n;
    else if (ans < 0) ans += n;

    if (ans > n) ans %= n;
    cout << ans << endl;
}