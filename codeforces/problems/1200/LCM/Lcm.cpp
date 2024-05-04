#include <bits/stdc++.h>

using namespace std;

int main() {
    long long b; cin >> b;

    long long i = 1, ans = 0;
    for (i = 1; i * i < b;i++)
        (b % i == 0) ? ans += 2 : ans;

    (i * i == b) ? ans++ : ans;
    cout << ans << endl;
}
