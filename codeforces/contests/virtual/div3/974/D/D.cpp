#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> jobs(k);
    for (auto& [l, r] : jobs) cin >> l >> r;
    sort(jobs.begin(), jobs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
        });
    int mx = -1;
    int f = -1;
    int mn = INF;
    int g = -1;
    multiset<int> ms;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j < k && jobs[j].first == i)
            ms.insert(jobs[j++].second);
        if (i >= d) {
            int z = ms.size();
            if (z > mx) {
                mx = z;
                f = i;
            }
            if (z < mn) {
                mn = z;
                g = i;
            }
            ms.erase(i - d + 1);
        }
    }
    assert(f != -1 && g != -1);
    cout << f - d + 1 << " " << g - d + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}