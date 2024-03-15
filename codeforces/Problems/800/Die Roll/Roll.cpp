#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    a = max(a, b);
    int num = 7 - a, den = 6;
    int gc = gcd(num, den);
    if (gc == 1) cout << num << "/" << den << endl;
    else cout << num / gc << "/" << den / gc << endl;
}