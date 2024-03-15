#include <bits/stdc++.h>

using namespace std;

int great(int x) {
    if (x == 0) return 0;
    int r = INT_MIN;
    while (x > 0) {
        r = max(r, x % 10);
        x /= 10;
    }
    return r;
}

int digits(int x, int b) {
    return (b == 10) ? floor(log10(x)) + 1 : floor((log(x)) / log(b)) + 1;
}

int conv(int x, int b) {
    int ans = 0, comp = 0;
    while (x > 0) {
        ans += x % 10 * pow(b, comp);
        x /= 10; comp++;
    }
    return ans;
}
int main() {
    int a, b; cin >> a >> b;
    int mx = INT_MIN;
    for (int i = max(great(a), great(b)) + 1; i <= 10; i++)
        mx = max(mx, digits(conv(a, i) + conv(b, i), i));
    cout << mx << endl;
}