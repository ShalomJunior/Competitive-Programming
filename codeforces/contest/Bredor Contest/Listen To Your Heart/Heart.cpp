#include <bits/stdc++.h>

using namespace std;

const double e = 1e-12;

bool equal(double x, double y) {
    return (abs(x - y) < e);
}

double a(double x) {
    return pow((sqrt(x - 3) - pow((3 * x + 2) / 2, 1. / 3)), 7.);
}

double b(double x) {
    return pow(x - sqrt((x * x - 1984) / 5.), 3.);
}
int main() {
    double x;
    for (x = 45; x < (double)INT_MAX; x++) {
        if (equal(a(x), b(x))) {
            cout << x << endl;
            return 0;
        }
    }

    cout << "Nothing" << endl;
}