#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; cin >> n;
    (n & 1) ? cout << (n - 1) / 2 - n << endl : cout << n / 2 << endl;
}