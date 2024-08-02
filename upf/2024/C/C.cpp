#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    cout << -s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}