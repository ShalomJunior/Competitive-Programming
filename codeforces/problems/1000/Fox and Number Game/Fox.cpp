#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        ms.insert(v);
    }

    int mn = *ms.begin();
    int mx = *prev(ms.end());
    while (mn < mx) {
        if (mn == 0) {
            ms.erase(*ms.begin());
            mn = *ms.begin();
            continue;
        }
        ms.insert(mx - mn);
        ms.erase(prev(ms.end()));

        mn = *ms.begin();
        mx = *prev(ms.end());
    }

    int ans = accumulate(ms.begin(), ms.end(), 0);
    cout << ans << endl;
}