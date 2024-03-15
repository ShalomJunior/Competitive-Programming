#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        q.push({ v, i + 1 });
    }

    int last = 0;
    while (!q.empty()) {
        if (q.front().first <= m)
            last = q.front().second;
        else
            q.push({ q.front().first - m, q.front().second });

        q.pop();
    }
    cout << last << endl;
}