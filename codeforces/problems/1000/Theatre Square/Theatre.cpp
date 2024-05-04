#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    double n, m, a;
    cin >> n >> m >> a;

    double ans = ceil(n / a) * ceil(m / a);
    cout << (ll)ans << endl;
}