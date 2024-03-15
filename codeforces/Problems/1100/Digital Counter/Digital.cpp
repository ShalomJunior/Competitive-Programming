#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = { 2, 7, 2, 3, 3, 4, 2, 5, 1, 2 };
    int n; cin >> n;
    int a = n % 10, b = n / 10;
    cout << v[a] * v[b] << endl;
}