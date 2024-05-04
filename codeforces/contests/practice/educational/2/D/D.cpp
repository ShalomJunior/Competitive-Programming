#include <bits/stdc++.h>
#define double long double
using namespace std;

const double PI = 3.14159265358979323846;
void solve() {
    double x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    double x2, y2, r2;
    cin >> x2 >> y2 >> r2;
    cout << fixed << setprecision(10);
    auto dx = __float128(x2 - x1);
    auto dy = __float128(y2 - y1);
    auto len = sqrtf128(dx * dx + dy * dy);
    if (r1 + r2 < len) {
        cout << 0 << endl;
        return;
    }
    if (len + min(r1, r2) <= max(r1, r2)) {
        cout << PI * min(r1 * r1, r2 * r2) << endl;
        return;
    }
    auto d = (len + r1 + r2) / 2;
    auto sub = sqrtf128(d * (d - r1) * (d - r2) * (d - len)) * 2;
    auto w1 = (len * len + r1 * r1 - r2 * r2) / (len * r1 * 2);
    auto w2 = (len * len + r2 * r2 - r1 * r1) / (len * r2 * 2);
    auto aera = __float128(1) * r1 * r1 * acosf128(w1) + __float128(1) * r2 * r2 * acosf128(w2);
    cout << (double)(aera - sub) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


// #include <bits/stdc++.h>
// #define double  long double
// using namespace std;

// const double PI = 3.14159265358979323846;
// void solve() {
//     double x1, y1, r1;
//     cin >> x1 >> y1 >> r1;
//     double x2, y2, r2;
//     cin >> x2 >> y2 >> r2;
//     cout << fixed << setprecision(10);
//     auto dx = (x2 - x1);
//     auto dy = (y2 - y1);
//     auto len = sqrtl(dx * dx + dy * dy);
//     if (r1 + r2 < len) {
//         cout << 0 << endl;
//         return;
//     }
//     if (len + min(r1, r2) <= max(r1, r2)) {
//         cout << PI * min(r1 * r1, r2 * r2) << endl;
//         return;
//     }
//     auto d = (len + r1 + r2) / 2;
//     auto sub = __sqrtf128(d * (d - r1) * (d - r2) * (d - len)) * 2;
//     auto  w1 = (len * len + r1 * r1 - r2 * r2) / (len * r1 * 2);
//     auto w2 = (len * len + r2 * r2 - r1 * r1) / (len * r2 * 2);
//     auto aera = __float128(1) * r1 * r1 * acosl(w1) + __float128(1) * r2 * r2 * acosl(w2);
//     cout << (double)(aera - sub) << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }
