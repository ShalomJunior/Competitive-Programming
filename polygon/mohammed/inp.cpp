#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int R = 10;
void generate() {
    int n = rand() % N + 1;
    int p = rand() % n;
    int k;
    stringstream ss;
    for (int i = 0; i < n; i++) {
        int x = 1 + (rand() % R);
        ss << x << " ";
        if (i == p) k = x;
    }
    assert(k > 0);
    cout << n << " " << k << endl;
    cout << ss.str() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    cout << t << endl;
    while (t--) generate();
}