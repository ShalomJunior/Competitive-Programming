#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b; cin >> a >> b;

    int f = 0, d = 0, l = 0;
    for (int i = 1; i < 7; i++) {
        if (abs(a - i) < abs(b - i))f++;
        else if (abs(a - i) == abs(b - i))d++;
        else l++;
    }

    cout << f << " " << d << " " << l << endl;
}