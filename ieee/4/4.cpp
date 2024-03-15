#include <bits/stdc++.h>
using namespace std;

vector<int> cycle = { 42, 20, 4, 16, 37, 58, 89, 145 };
void solve() {
    long long a, b; cin >> a >> b;
    long long ans = b - a + 1;
    for (auto& c : cycle) {
        if (a <= c && c <= b) {
            ans--;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}




