#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
int get(vector<int>& a, int k) {
    int n = a.size();
    if (n == 0) return 0;
    int ans = 0;
    int until = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > until) {
            ans++;
            until = a[i] + k - 1;
        }
    }
    return ans;
}

void solve() {
    int n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    vector<int> a(n), b(m);
    for (auto& c : a)cin >> c;
    for (auto& c : b)cin >> c;
    vector<int> idx = { -1 };
    int match = 0;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        if (a[i] == b[j]) {
            idx.push_back(i);
            match++;
            j++;
        }
    }
    if (match != m) {
        cout << -1 << endl;
        return;
    }
    idx.push_back(n);
    int w = idx.size();
    int ans = 0;
    for (int i = 1; i < w; i++) {
        int l = idx[i - 1], r = idx[i];
        int len = r - l - 1;
        if (len == 0)continue;
        int mx = max(l == -1 ? 0 : a[l], r == n ? 0 : a[r]);
        vector<int> sup;
        int M = 0;
        for (int j = l + 1; j < r; j++) {
            if (a[j] > mx) {
                sup.push_back(j);
                M = max(M, a[j]);
            }
        }
        int need = get(sup, k);
        int add = INF;
        for (int c = 0; c * k <= len; c++) {
            //if (c < need)continue;
            if (c == 0 && M > mx) continue;
            int rem = len - c * k;
            add = min(add, c * x + rem * y);
        }
        if (add == INF) {
            cout << -1 << endl;
            return;
        }
        ans += add;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// const int INF = 1e18;
// void solve() {
//     int n, m, x, k, y;
//     cin >> n >> m >> x >> k >> y;
//     vector<int> a(n), b(m);
//     for (auto& c : a)cin >> c;
//     for (auto& c : b)cin >> c;
//     vector<int> idx = { -1 };
//     int match = 0;
//     for (int i = 0, j = 0; i < n && j < m; i++) {
//         if (a[i] == b[j]) {
//             idx.push_back(i);
//             match++;
//             j++;
//         }
//     }
//     if (match != m) {
//         cout << -1 << endl;
//         return;
//     }
//     idx.push_back(n);
//     for (auto& c : idx) cout << c << " ";
//     cout << endl;
//     int w = idx.size();
//     int ans = 0;

//     for (int i = 1; i < w; i++) {
//         cout << "i  = " << i << endl;
//         int l = idx[i - 1], r = idx[i];
//         cout << l << " -- " << r << endl;
//         int len = r - l - 1;
//         if (len == 0)continue;
//         cout << "where" << endl;
//         int mx = max(l == -1 ? 0 : a[l], r == n ? 0 : a[r]);
//         int endL = r, endR = l;
//         for (int j = l + 1; j < r; j++) {
//             if (a[j] > mx) {
//                 endL = min(endL, j);
//                 endR = max(endR, j);
//             }
//         }
//         cout << "len = " << len << endl;
//         cout << endL << " -> " << endR << endl;
//         int z = max(endR - endL + 1, 0LL);
//         int add = INF;
//         for (int c = 0; c * k <= len; c++) {
//             cout << c << " | " << k << endl;
//             if (c * k < z)continue;
//             int rem = len - c * k;
//             add = min(add, c * x + rem * y);
//         }
//         if (add == INF) {
//             cout << -1 << endl;
//             return;
//         }
//         ans += add;
//         cout << ans << " @" << endl;
//     }
//     cout << ans << endl;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }

