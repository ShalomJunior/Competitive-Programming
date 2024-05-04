#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; double t1, t2, k;
    cin >> n >> t1 >> t2 >> k;

    priority_queue<pair<double, int>> pq;
    for (int i = 1; i <= n; i++) {
        double s1, s2; cin >> s1 >> s2;
        double mx = max(s1 * t1 * (100 - k) / 100. + s2 * t2, s2 * t1 * (100 - k) / 100. + s1 * t2);
        pq.push({ mx, -i });
    }

    while (!pq.empty()) {
        printf("%d %.2f\n", abs(pq.top().second), pq.top().first);
        pq.pop();
    }
}