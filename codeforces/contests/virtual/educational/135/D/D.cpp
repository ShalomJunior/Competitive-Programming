#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    string s; cin >> s;
    int n = s.length();
    auto get = [&](int i, int j) {
        if (s[i] < s[j]) return 1;
        if (s[i] == s[j]) return 0;
        return -1;
        };
    vector<vector<int>> dp(n, vector<int>(n, INF));
    function<int(int, int, int, int)> go = [&](int i, int j, int a, int b) {
        if (i >= j) return get(a, b);
        if (dp[i][j] != INF) {
            return dp[i][j] == 0 ? get(a, b) : dp[i][j];
        }
        int w = go(i + 2, j, i, i + 1);
        int x = go(i + 1, j - 1, i, j);
        int y = go(i + 1, j - 1, j, i);
        int z = go(i, j - 2, j, j - 1);
        if ((w == 1 && x == 1) || (y == 1 && z == 1)) {
            return dp[i][j] = 1;
        }
        else if ((w == -1 && x == -1) && (y == -1 && z == -1)) {
            return dp[i][j] = -1;
        }
        dp[i][j] = 0;
        return  get(a, b);
        };
    go(0, n - 1, 0, 0);
    if (dp[0][n - 1] == 1) cout << "Alice";
    else if (dp[0][n - 1] == 0) cout << "Draw";
    else cout << "Bob";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}


// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;
// void solve() {
//     string s; cin >> s;
//     int n = s.length();
//     auto get = [&](int i, int j) {
//         if (s[i] < s[j]) return 1;
//         if (s[i] == s[j]) return 0;
//         return -1;
//         };
//     vector<vector<int>> dp(n, vector<int>(n, INF));
//     function<int(int, int, int, int)> go = [&](int i, int j, int a, int b) {
//         if (i >= j) return get(a, b);
//         if (dp[i][j] != INF) {
//             cerr << i << " " << j << " " << dp[i][j] << " " << get(a, b) << endl;
//             return dp[i][j] == 0 ? get(a, b) : dp[i][j];
//         }
//         int w = go(i + 2, j, i, i + 1);
//         int x = go(i + 1, j - 1, i, j);
//         int y = go(i + 1, j - 1, j, i);
//         int z = go(i, j - 2, j, j - 1);
//         if ((w == 1 && x == 1) || (y == 1 && z == 1)) {
//             cerr << i << ": " << j << " -> " << endl;
//             return dp[i][j] = 1;
//         }
//         else if ((w == -1 && x == -1) && (y == -1 && z == -1)) {
//             cerr << i << ": " << j << " # " << endl;

//             return dp[i][j] = -1;
//         }
//         cerr << "get " << i << " " << j << get(a, b) << endl;
//         dp[i][j] = 0;
//         return  get(a, b);
//         };
//     go(0, n - 1, 0, 0);
//     if (dp[0][n - 1] == 1) cout << "Alice";
//     else if (dp[0][n - 1] == 0) cout << "Draw";
//     else cout << "Bob";
//     cout << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; cin >> t;
//     while (t--) solve();
// }
