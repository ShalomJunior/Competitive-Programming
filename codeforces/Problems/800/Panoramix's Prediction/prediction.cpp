#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)return false;

    return true;
}

int next_prime(int n) {
    for (int i = n + 1; i < 50; i++)
        if (is_prime(i)) return i;
    return -1;
}

int main() {
    int n, m; cin >> n >> m;
    if (next_prime(n) == m) cout << "YES" << endl;
    else cout << "NO" << endl;
}