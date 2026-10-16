#include <bits/stdc++.h>
using namespace std;

template <typename T>
class PrefixSum2D {
private:
    vector<vector<T>> g;
    int rows, cols;

public:
    PrefixSum2D(const vector<vector<T>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        g.resize(rows + 1, vector<T>(cols + 1, 0));

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                g[i][j] = matrix[i - 1][j - 1]
                    + g[i - 1][j]
                    + g[i][j - 1]
                    - g[i - 1][j - 1];
            }
        }
    }

    T query(int r1, int c1, int r2, int c2) const {
        r1++; c1++; r2++; c2++;
        return g[r2][c2]
            - g[r1 - 1][c2]
            - g[r2][c1 - 1]
            + g[r1 - 1][c1 - 1];
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x > k) a[i][j] = 1;
        }
    }
    PrefixSum2D g(a);
    for (int len = min(n, m); len > 0; len--) {
        int aera = len * len;
        for (int i = 0; i + len - 1 < n; i++) {
            for (int j = 0; j + len - 1 < m; j++) {
                int cnt = g.query(i, j, i + len - 1, j + len - 1);
                int z = aera - cnt;
                bool f = false;
                if (aera & 1) {
                    if (z >= (aera + 1) / 2) f = true;
                }
                else {
                    if (z >= aera / 2) f = true;
                }
                if (f) {
                    cout << aera << endl;
                    return;
                }
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*

#include <bits/stdc++.h>
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x > k) a[i][j] = 1;
        }
    }
    PrefixSum2D g(a);
    for (int len = min(n, m); len > 0; len--) {
        cerr << "len = " << len << endl;
        int aera = len * len;
        for (int i = 0; i + len - 1 < n; i++) {
            for (int j = 0; j + len - 1 < m; j++) {
                cerr << "calling" << endl;
                int cnt = g.query(i, j, i + len - 1, j + len - 1);
                cerr << "end" << endl;

                int z = aera - cnt;
                bool f = false;
                if (aera & 1) {
                    if (z >= (aera + 1) / 2) f = true;
                }
                else {
                    if (z >= aera / 2) f = true;
                }
                if (f) {
                    cout << aera << endl;
                    return;
                }
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}*/