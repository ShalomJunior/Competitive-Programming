#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;
    int need = (k * w * (w + 1) / 2 > n) ? (k * w * (w + 1) / 2) - n : 0;
    cout << need << endl;
}
