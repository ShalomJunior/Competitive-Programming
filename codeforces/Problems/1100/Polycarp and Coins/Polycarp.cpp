#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int sb = n / 3;
    if (n % 3 == 0) printf("%d %d\n", sb, sb);
    else if (n % 3 == 1) printf("%d %d\n", sb + 1, sb);
    else printf("%d %d\n", sb, sb + 1);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}