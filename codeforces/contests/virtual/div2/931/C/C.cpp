#include <bits/stdc++.h>
using namespace std;

struct Equation {
    double a;
    double b;
    double c;
};

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

bool solveSystem(const Equation& eq1, const Equation& eq2, double& x, double& y) {
    double determinant = eq1.a * eq2.b - eq1.b * eq2.a;
    if (determinant == 0) {
        return false;
    }
    x = (eq1.c * eq2.b - eq1.b * eq2.c) / determinant;
    y = (eq2.a * eq1.c - eq1.a * eq2.c) / determinant;
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i : {1, n}) {
        for (int j : {1, m}) {
            a.push_back(query(i, j));
        }
    }
    vector<Equation> b;
    b.push_back(Equation{ 1, 1, (double)a[0] - 2 });
    b.push_back(Equation{ 1, -1, (double)a[1] + 1 - m });
    b.push_back(Equation{ -1, 1, (double)a[2] + 1 - n });
    b.push_back(Equation{ -1, -1, (double)a[3] + 1 - (n + m) });
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            double x, y;
            int rx = ceil(x);
            int ry = ceil(y);
            if (solveSystem(b[i], b[j], x, y)) {
                if (1 <= rx && rx <= n && 1 <= ry && ry <= m) {
                    cout << rx << " " << ry << endl;
                    return;
                }
            }
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}