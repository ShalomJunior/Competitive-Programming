#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; cin >> n;
    long long ans = static_cast<long long>(pow(2, n + 1));
    cout << ans - 2 << endl;
}