#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;
const string S = "01032025";
map<char, int> H;
void solve() {
    int n;
    cin >> n;
    int ans = INF;;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h[x]++;
        bool f = true;
        for (int j = 0; j <= 9; j++) {
            if (h[j] < H[j]) {
                f = false;
            }
        }
        if (f) {
            ans = min(ans, i + 1);
        }
    }
    cout << (ans == INF ? 0 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (auto& c : S) H[c - '0']++;
    int t; cin >> t;
    while (t--)solve();
}
