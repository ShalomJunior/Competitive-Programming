#include <bits/stdc++.h>
#define ll long long
#define mine vector<vector<ll>>

using namespace std;

mine mult(mine curr, mine times) {
    int n = curr.size();
    mine ans(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] += curr[i][k] * times[k][j];
            }
        }
    }
    return ans;
}

bool equal(mine a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++) {
            if (a[i][j] != 0) return false;
        }
    }
    return true;
}

mine cp(mine a) {
    int n = a.size();
    mine ans(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = a[i][j];
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    mine mat(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    mine times = cp(mat);
    int ans = 1;
    while (!equal(mat)) {
        mat = mult(mat, times);
        ans++;
    }
    if (ans > 9) ans = 9;
    cout << (ans) << endl;
}