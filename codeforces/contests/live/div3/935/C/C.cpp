#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 2, -1);
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        a[i] = x - '0';
    }
    double ans = INF;
    int pos;
    int l = 0;
    int r = count(a.begin(), a.end(), 1);
    for (int i = 0; i <= n + 1; i++) {
        if (a[i] == 0)l++;
        if (a[i] == 1)r--;
        int x = i;
        int y = n - i;
        if (l >= (x + 1) / 2 && r >= (y + 1) / 2) {
            if (abs((double)n / 2 - i) < ans) {
                pos = i;
                ans = abs(n / 2 - i);
            }
        }
    }
    cout << pos << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
