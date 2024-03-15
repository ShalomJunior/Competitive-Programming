#include <bits/stdc++.h>

using namespace std;

void add(vector<int>& ans, int f, int s) {
    if (f < s) {
        for (int i = f; i <= s; i++)ans.push_back(i);
    }
    else {
        for (int i = f; i >= s; i--)ans.push_back(i);
    }
}

void out(vector<int>& ans) {
    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

void solve() {
    int n; cin >> n;
    if (n == 3) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    if (n & 1) {
        add(ans, n, n / 2 + 2);
        add(ans, 1, 1 + n / 2);
    }
    else { add(ans, n, 1); }

    out(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}