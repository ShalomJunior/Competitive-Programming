#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> s;
    while (!s.count(n)) {
        s.insert(n);
        n++;
        while (n % 10 == 0) n /= 10;
    }
    cout << s.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}