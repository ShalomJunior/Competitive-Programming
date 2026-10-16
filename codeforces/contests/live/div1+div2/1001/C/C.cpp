#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 55;
int comb[MAX][MAX];

void precompute() {
    for (int i = 0; i < MAX; ++i) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

signed main() {
    precompute();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << a[0] << endl;
            continue;
        }
        int max_sum = 0;
        for (int num : a) {
            max_sum += num;
        }
        for (int k = 1; k <= n - 1; ++k) {
            int current_sum = 0;
            for (int j = 0; j < n; ++j) {
                if (j > k) {
                    continue;
                }
                int c = comb[k][j];
                int sign = (j % 2 == 0) ? 1 : -1;
                current_sum += sign * c * a[j];
            }
            if (k % 2 == 1) {
                current_sum = abs(current_sum);
            }
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        cout << max_sum << endl;
    }
}