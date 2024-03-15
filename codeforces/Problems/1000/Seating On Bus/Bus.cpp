#include<bits/stdc++.h>

using namespace std;

bool out(queue<int>& q) {
    bool ans = false;
    if (!q.empty()) {
        cout << q.front() << " ";
        ans = true, q.pop();
    }
    return ans;
}

int main() {
    int n, m; cin >> n >> m;
    vector<queue<int>> places(4);

    for (int i = 1; i <= m; i++) {
        if (i <= 2 * n) {
            if (i & 1) places[0].push(i);
            else places[3].push(i);
        }
        else {
            if (i & 1) places[1].push(i);
            else places[2].push(i);
        }
    }

    bool tk = true;
    while (tk) {
        tk = false;
        tk |= out(places[1]);
        tk |= out(places[0]);
        tk |= out(places[2]);
        tk |= out(places[3]);
    }
    cout << endl;
}