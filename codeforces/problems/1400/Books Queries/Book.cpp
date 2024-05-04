#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;

    unordered_map<int, int> left, right;

    int l = 0, r = 0;
    while (q--) {
        char c; int id;
        cin >> c >> id;

        if (c == 'L') {
            l++;
            left[id] = l;
        }
        else if (c == 'R') {
            r++;
            right[id] = r;
        }
        else {
            if (left.find(id) != left.end()) {
                cout << min(l - left[id], r + left[id] - 1) << endl;
            }
            else {
                cout << min(r - right[id], l + right[id] - 1) << endl;
            }
        }
    }
}