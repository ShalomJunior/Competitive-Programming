#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int f(int n) {
    int ans = 0;
    while (n % 2 == 0) {
        ans++;
        n /= 2;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int odds = 0;
    for (auto& c : a) {
        cin >> c;
        odds += c % 2;
    }
    if (odds) {
        cout << n - odds << endl;
        return;
    }
    int ans = INF;
    for (auto& c : a) {
        int need = f(c);
        ans = min(ans, need + n - 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}