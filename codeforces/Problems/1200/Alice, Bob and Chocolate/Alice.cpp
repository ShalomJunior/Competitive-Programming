#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v)cin >> c;

    if (n == 1) {
        cout << "1 0" << endl;
        return 0;
    }
    int left = 0, right = n - 1;
    int start = v[0], end = v[n - 1];
    while (true) {
        if (start <= end) {
            if (left + 1 != right) start += v[++left];
            else break;
        }
        else {
            if (left != right - 1) end += v[--right];
            else break;
        }
    }
    left++;
    cout << left << " " << n - left << endl;
}