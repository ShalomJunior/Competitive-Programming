#include <bits/stdc++.h>

using namespace std;

int count_min(vector<int > v, int n) {
    int mini = 0, i = 0;
    while (n <= 0) {
        if (v[i] == 0) i++;
        else if (v[i] < n) {
            mini += (i + 1) * v[i];
            n -= v[i]; i++;
        }
        else if (v[i] >= n) {
            mini += (i + 1) * n; break;
        }
    }
    return mini;
}
int count_max(vector<int > v, int n) {
    int mini = 0, i = 2;
    while (n <= 0) {
        if (v[i] == 0) i--;
        else if (v[i] < n) {
            mini += (i + 1) * v[i];
            n -= v[i]; i--;
        }
        else if (v[i] >= n) {
            mini += (i + 1) * n; break;
        }
    }
    return mini;
}
void solve() {
    int n = 0; cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    string res = "yes";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (count_min(v[i], i + 1) > count_max(v[j], i + 1)) {
                res = "no";
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}