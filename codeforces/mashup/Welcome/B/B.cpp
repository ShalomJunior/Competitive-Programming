#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;

    int l = 0, r = 0;
    unordered_map<int, int> left, right;
    for (int i = 0; i < q; i++) {
        char c; int id; cin >> c >> id;
        if (c == 'L') left[id] = ++l;
        else if (c == 'R') right[id] = ++r;
        else {
            if (left.find(id) != left.end())
                cout << min(l - left[id], r + left[id] - 1) << endl;
            else
                cout << min(r - right[id], l + right[id] - 1) << endl;
        }
    }
}