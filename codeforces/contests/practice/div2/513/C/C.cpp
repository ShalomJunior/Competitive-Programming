#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>
class PrefixSum2D {
private:
    vector<vector<T>> g;
    int rows, cols;

public:
    // Constructor
    PrefixSum2D(const vector<vector<T>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        g.resize(rows + 1, vector<T>(cols + 1, 0));

        // Compute the 2D prefix sum
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                g[i][j] = matrix[i - 1][j - 1]
                    + g[i - 1][j]
                    + g[i][j - 1]
                    - g[i - 1][j - 1];
            }
        }
    }

    // Query the sum of elements in the submatrix from (r1, c1) to (r2, c2)
    T query(int r1, int c1, int r2, int c2) const {
        r1++; c1++; r2++; c2++; // Convert to 1-based index for internal use
        return g[r2][c2]
            - g[r1 - 1][c2]
            - g[r2][c1 - 1]
            + g[r1 - 1][c1 - 1];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int x;
    cin >> x;
    int ans = 0;
    for (int li = 0; li < n; li++) {
        for (int lr = li + 1; lr < n; lr++) {
            int x =
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
