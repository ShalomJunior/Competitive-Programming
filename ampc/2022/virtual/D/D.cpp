#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    if (n > k) { cout << "Not possible" << endl; return 0; }
    k -= n;
    if (k % 2 == 0) { cout << "Possible" << endl; return 0; }
    cout << "Not possible" << endl;
}