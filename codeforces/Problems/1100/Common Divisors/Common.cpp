#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> v(n);
    cin >> v[0];
    long long gd = v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        gd = gcd(gd, v[i]);
    }

    long long i, cnt = 0;
    for (i = 1; i * i <= gd; i++)
        (gd % i == 0) ? cnt += 2 : cnt;

    i--;
    if (i * i == gd) cout << cnt - 1 << endl;
    else cout << cnt << endl;
}