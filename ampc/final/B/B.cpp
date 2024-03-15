#include <bits/stdc++.h>
using namespace std;

void solve() {
    double x1, x2, y1, y2;
    double x;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x;
    double a = y1 - y2;
    assert(x1 != x2);
    a /= x1 - x2;


    double b = y1 - a * x1;
    double y = a * x + b;
    printf("%.5f\n", y);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)solve();
}