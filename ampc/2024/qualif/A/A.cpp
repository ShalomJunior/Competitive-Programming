#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 9e18;
const int N = 3e7;
vector<int> dp(N, INF);
int n, x, y, ans;
void go(int c, int cost, bool f = false, bool g = false) {
    cout << c << endl;
    dp[c] = cost;
    if (c >= n) {
        ans = min(ans, cost + (c - n) * x);
        return;
    }
    if (f == false) {
        if (!g && c - 1 > 0 && cost + x + y < dp[(c - 1) * 2])
            go((c - 1) * 2, cost + x + y, true);
    }
    for (int i = f ? 1 : 0; c + i <= n; i++) {
        if (c + i == n) {
            ans = min(ans, cost + i * x);
        }
        else {
            if (cost + i * x + y < dp[(c + i) * 2])
                go((c + i) * 2, cost + i * x + y);
        }
    }
}

void solve() {
    cin >> n >> x >> y;
    ans = INF;
    go(0, 0, true);
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

// const int INF = 9e18;
// const int N = 3e7;
// vector<int> dp(N, INF);
// int n, x, y, ans;
// void go(int c, int cost, bool f = false) {
//     dp[c] = cost;
//     if (c >= n) {
//         ans = min(ans, cost + (c - n) * x);
//         return;
//     }
//     if (f == false) {
//         for (int i = 1; i < 10 && c - i > c / 2; i++) {
//             if (cost + i * x + y <= dp[(c - i) * 2])
//                 go((c - i) * 2, cost + i * x + y);
//         }
//     }
//     for (int i = f ? 1 : 0; c + i <= n; i++) {
//         if (c + i == n) {
//             ans = min(ans, cost + i * x);
//         }
//         else {
//             if (cost + i * x + y <= dp[(c + i) * 2])
//                 go((c + i) * 2, cost + i * x + y);
//         }
//     }
// }

// void solve() {
//     cin >> n >> x >> y;
//     ans = INF;
//     go(0, 0, true);
//     cout << ans << endl;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }
