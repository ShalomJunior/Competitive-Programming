#include <bits/stdc++.h>
using namespace std;

const int N = 105;
void solve() {
    int n; cin >> n;
    vector<int> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    int ans = 0;
    for (int k = 0; k < 2; k++) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                ans += i;
                flag = true;
                break;
            }
            a[i]--;
        }
        if (!flag) ans += n;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}