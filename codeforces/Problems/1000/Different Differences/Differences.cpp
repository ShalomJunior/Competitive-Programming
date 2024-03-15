#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k, n; cin >> k >> n;

    vector<int> ans;
    int start = 1;
    for (int i = 0; i < k; i++) {
        int next = start + i;
        if (n - next >= (k - 1 - i)) {
            start = next;
            ans.push_back(start);
        }
        else {
            ans.push_back(++start);
        }
    }

    for (auto& c : ans)
        cout << c << " ";
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}