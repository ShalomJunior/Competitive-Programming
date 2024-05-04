#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> L(n + 1, vector<int>(k + 1, INF));
    vector<vector<int>> R(n + 1, vector<int>(k + 1, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i <= j) {
                L[i][j] = min(L[i][j], (i + 1) * a[i]);
            }
            else {
                L[i][j] = min(L[i][j], (j + 1) * a[i] + L[i - j - 1][k - j]);
            }
            if (j) L[i][j] = min(L[i][j], L[i][j - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            if (j < n - 1 - i) {
                R[i][j] = min(R[i][j], a[i] * (j + 1) + R[i + j + 1][0]);
            }
            else {
                R[i][j] = min(R[i][j], a[i] * (n - i));
            }
            if (j) R[i][j] = min(R[i][j], R[i][j - 1]);
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int z = 0; z + j <= k; z++) {
                int l = L[i][j];
                int r = i + 1 < n ? R[i + 1][z] : 0;
                ans = min(ans, l + r);
                ans = min(ans, l + R[i][z] - a[i]);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}

/*

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> L(n + 1, vector<int>(k + 1, INF));
    vector<vector<int>> R(n + 1, vector<int>(k + 1, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i <= j) {
                L[i][j] = min(L[i][j], (i + 1) * a[i]);
                cerr << "@ " << L[i][j] << endl;
            }
            else {
                L[i][j] = min(L[i][j], (j + 1) * a[i] + L[i - j - 1][k - j]);
                cerr << "đ " << L[i][j] << endl;
            }
            if (j) L[i][j] = min(L[i][j], L[i][j - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            if (j < n - 1 - i) {
                cerr << "|" << endl;
                R[i][j] = min(R[i][j], a[i] * (j + 1) + R[i + j + 1][0]);
            }
            else {
                cerr << "←" << endl;
                R[i][j] = min(R[i][j], a[i] * (n - i));
            }
            if (j) R[i][j] = min(R[i][j], R[i][j - 1]);
            cerr << i << " ← " << j << " " << R[i][j] << endl;
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        cout << "i = " << i << endl;
        for (int j = 0; j <= k; j++) {
            for (int z = 0; z + j <= k; z++) {
                cerr << j << " ħħħħħ " << z << endl;
                int l = L[i][j];
                int r = i + 1 < n ? R[i + 1][z] : 0;
                cerr << l << " " << r << endl;
                ans = min(ans, l + r);
                cerr << "-----> " << l << " " << R[i][z] << " " << a[i] << endl;
                ans = min(ans, l + R[i][z] - a[i]);
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
*/
/*


#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> L(n + 1, vector<int>(k + 1, INF));
    vector<vector<int>> R(n + 1, vector<int>(k + 1, INF));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            if (i < j) {
                L[i][j] = min(L[i][j], (i + 1) * a[i]);
                cerr << "@ " << L[i][j] << endl;
            }
            else {
                L[i][j] = min(L[i][j], (j + 1) * a[i] + (i - j - 1 >= 0 ? L[i - j - 1][k - j] : 0));
                cerr << "đ " << L[i][j] << endl;

            }
            if (j <= n - 1 - i) {
                cerr << "|" << endl;
                R[i][j] = min(R[i][j], a[i] * (j + 1) + (i + j + 1 < n ? R[i + j + 1][k - j] : 0));
            }
            else {
                cerr << "←" << endl;
                R[i][j] = min(R[i][j], a[i] * (n - i));
            }
            cerr << i << " ← " << j << " " << R[i][j] << endl;
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        cout << "i = " << i << endl;
        for (int j = 0; j <= k; j++) {
            for (int z = 0; z + j <= k; z++) {
                int l = L[i][j];
                int r = i + 1 < n ? R[i + 1][z] : 0;
                cerr << l << " " << r << endl;
                ans = min(ans, l + r);
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
*/