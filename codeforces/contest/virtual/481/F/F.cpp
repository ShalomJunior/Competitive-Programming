#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<Mine> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i;
    }
    vector<int> sub(n);
    while (k--) {
        int x, y; cin >> x >> y;
        --x, --y;
        if (a[x].F < a[y].F) sub[y]--;
        if (a[x].F > a[y].F) sub[x]--;
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    for (int i = 1; i < n; i++) {
        if (i && a[i - 1].F == a[i].F) {
            ans[a[i].S] = ans[a[i - 1].S];
            continue;
        }
        ans[a[i].S] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + sub[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}