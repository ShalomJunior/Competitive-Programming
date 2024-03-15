#include <bits/stdc++.h>
using namespace std;

int minPartition(vector<int>& used, vector<int>& total) {
    int n = used.size();
    int tot = accumulate(used.begin(), used.end(), 0);
    if (tot == 0) return 0;
    sort(total.rbegin(), total.rend());
    for (int s = 0, i = 0; i < n; i++) {
        s += total[i];
        if (s >= tot) return i + 1;
    }
    return n;
}
/*
3 2 1 3 1
3 5 3 5 5

3+2+1+3+1 = 10

10

5 5 5 3 3
have = 5 + 5 = 10

*/
void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
