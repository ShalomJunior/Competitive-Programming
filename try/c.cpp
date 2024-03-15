#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<double> v(n);
    v[0] = 2;
    v[1] = 1;
    v[2] = 0;

    for (int i = 3; i < n; i++)
        v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) / 3.;

    cout << v[n - 1] << endl;
}