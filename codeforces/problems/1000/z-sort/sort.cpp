#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        ms.insert(v);
    }

    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            ans[i - 1] = *ms.begin();
            ms.erase(ms.begin());
        }
        else {
            ans[i - 1] = *prev(ms.end());
            ms.erase(prev(ms.end()));
        }
    }

    for (int i = 0; i < n - 1; i += 2) {
        if (ans[i] > ans[i + 1]) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    for (auto& c : ans)
        cout << c << " ";
    cout << endl;
}