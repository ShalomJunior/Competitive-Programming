#include <bits/stdc++.h>
#define int long long
using namespace std;

bool good(int arr[], int& N, int& K,
    int& median)
{
    int pre[N];
    for (int i = 0; i < N; i++) {
        if (arr[i] >= median)
            pre[i] = 1;
        else
            pre[i] = -1;

        if (i > 0)
            pre[i] += pre[i - 1];
    }

    // mx denotes the maximum
    // sum of a sub array having
    // length at least k.
    int mx = pre[K - 1];

    // mn denotes the minimum
    // prefix sum seen so far.
    int mn = 0;

    for (int i = K; i < N; i++) {
        mn = min(mn, pre[i - K]);
        mx = max(mx, pre[i] - mn);
    }
    if (mx > 0)
        return true;
    return false;
}

// Function to find the maximum median
// of a sub array having length at least K
int maxMedian(int arr[], int N, int K)
{
    // l and r denote the left and right
    // boundary for binary search algorithm
    int l = 1, r = N + 1;

    // Variable to keep track
    // of maximum median
    int mx_median = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(arr, N, K, mid)) {
            mx_median = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return mx_median;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << maxMedian(a, n, 3) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
