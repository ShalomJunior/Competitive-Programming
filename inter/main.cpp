#include <bits/stdc++.h>
using namespace std;

int minPartition(vector<int>& used, vector<int>& total) {
    int n = used.size();
    int tot = accumulate(used.begin(), used.end(), 0);
    sort(total.rbegin(), total.rend());
    if (tot == 0) return 0;
    for (int s = 0, i = 0; i < n; i++) {
        s += total[i];
        if (s >= tot) return i + 1;
    }
    return n;
}

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
