#include <bits/stdc++.h>

using namespace std;

int sm(int n, int base) {
    int ans = 0;
    while (n > 0) {
        ans += n % base;
        n /= base;
    }
    return ans;
}

int main() {
    int n; cin >> n;

    int ans = 0;
    for (int i = 2; i < n; i++) {
        ans += sm(n, i);
    }

    int nb = n - 2;
    int g = gcd(ans, nb);

    printf("%d/%d\n", ans / g, nb / g);
}