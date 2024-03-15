#include <bits/stdc++.h>

using namespace std;

bool valid(int y) {
    unordered_map<int, int> h;
    while (y > 0)
        h[y % 10]++, y /= 10;

    for (auto p : h)
        if (p.second > 1) return false;

    return true;
}

int main() {
    int y; cin >> y;
    while (!valid(++y));
    cout << y << endl;
}