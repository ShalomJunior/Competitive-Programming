#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int get(set<int>& s) {
    int ans = 1;
    while (s.count(ans)) ans++;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(2 * n);
    vector<pair<int, int>> a(n, { INF, -1 });
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        v[i] = x;
        a[x].first = min(a[x].first, i);
        a[x].second = max(a[x].second, i);
    }
    int i = a[0].first, j = a[0].second;
    set<int> s;
    while (i <= j) {
        if (v[i] != v[j]) {
            cout << 1 << endl;
            return;
        }
        s.insert(v[i]);
        i++;
        j--;
    }
    int ans = get(s);
    for (int i : {a[0].first, a[0].second}) {
        s.clear();
        for (int k = 0; k < n && i - k >= 0 && i + k < n; k++) {
            if (v[i - k] != v[i + k]) {
                break;
            }
            s.insert(v[i - k]);
            s.insert(v[i + k]);
        }
        ans = max(ans, get(s));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}