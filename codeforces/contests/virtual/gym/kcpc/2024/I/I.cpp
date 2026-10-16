#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) a.push_back({ x, 1 });
        else {
            if (a.back().first == x) {
                a.back().second++;
            }
            else {
                a.push_back({ x, 1 });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}