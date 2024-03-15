#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    deque<int> dq;
    for (int i = 0; i < n;i++) {
        int v; cin >> v;
        dq.push_back(v);
    }

    int f = 0, l = 0;
    int tour = 0;
    while (!dq.empty()) {
        tour++;
        if (*dq.begin() > *prev(dq.end())) {
            if (tour & 1) f += *dq.begin();
            else l += *dq.begin();
            dq.erase(dq.begin());
        }
        else {
            if (tour & 1) f += *prev(dq.end());
            else l += *prev(dq.end());
            dq.erase(prev(dq.end()));
        }
    }

    cout << f << " " << l << endl;
}