#include <bits/stdc++.h>
#define mine pair<int, int>
#define F first
#define S second
using namespace std;

double r(double a) { return a * a; }

double Euler(mine& A, mine& B) { return sqrt(r(A.F - B.F) + r(A.S - B.S)); }

void solve() {
    int n; cin >> n;
    unordered_map<int, pair<int, int>> db;
    for (int i = i; i <= 2 * n; i++) {
        string s; int x, y;
        cin >> s >> x >> y;
        db[i] = { x, y };
    }

    double ans = 1e10;
    vector<int> num(n);
    iota(num.begin(), num.end(), n + 1);
    do {
        double curr = 0;
        for (int i = 0; i < n; i++) {
            cout << num[i] << " ";;
            curr += Euler(db[i], db[num[i]]);
        }
        cout << endl;
        ans = min(ans, curr);

    } while (next_permutation(num.begin(), num.end()));
    printf("%.2f\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}