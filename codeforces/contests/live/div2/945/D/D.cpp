#include <bits/stdc++.h>
using namespace std;

const int N = 25;

bool check(vector<int> a, int add, int k) {
    a.push_back(add);
    int n = a.size();
    int s = accumulate(a.begin(), a.end(), 0LL);
    if (s < k) return false;
    vector<bool> dp(s + 1), temp(s + 1);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        temp = dp;
        for (int j = 0; j <= s; j++) {
            if (temp[j]) {
                dp[j + a[i]] = true;
            }
        }
    }
    int cnt = count(dp.begin(), dp.end(), false);
    return dp[k];
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    int x = n;
    while (x) {
        for (int i : { 1, 0, -1 }) {
            if (x + i >= 0 && !check(ans, x + i, k)) {
                ans.push_back(x + i);
                break;
            }
        }
        x /= 2;
    }
    cerr << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}


// bool check(std::vector<int>& arr, int k, int s) {
//     int n = arr.size();
//     // Create a boolean array to store the state of each sum from 0 to s
//     std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(s + 1, false));

//     // If the sum is 0, then the answer is true for any subset (empty subset)
//     for (int i = 0; i <= n; ++i)
//         dp[i][0] = true;

//     // Fill the dp array
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= s; ++j) {
//             if (arr[i - 1] <= j)
//                 dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
//             else
//                 dp[i][j] = dp[i - 1][j];
//         }
//     }
//     for (int i = 0; i <= s; i++) {
//         if (i == k) {
//             if (dp[n][k])
//                 return false;
//         }
//         else if (!dp[n][i]) {
//             return false;
//         }
//     }
//     return true;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int N = 6;
    // vector<int> p;
    // for (int i = 1; i < 53; i++) p.push_back(i);
    // int z = 6;
    // function<void(int, vector<int>)> go = [&](int i, vector<int> x) {
    //     if (i == z) {
    //         //for (auto& c : x) cout << c << " ";
    //         //cout << endl << endl;;

    //         if (check(x, 29, 52)) {
    //             for (auto& c : x) cout << c << " ← ";
    //             cout << endl;
    //         }
    //         return;
    //     }
    //     for (auto& c : p) {
    //         vector<int> temp = x;
    //         temp.push_back(c);
    //         go(i + 1, temp);
    //     }
    //     };
    // go(0, vector<int>());
    // cerr << "end" << endl;
    int t; cin >> t;
    while (t--)solve();
}
