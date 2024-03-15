#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
void solve() {
    int n; cin >> n;
    printf("%.9f\n", 1. / tan(PI / (2 * n)));
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}