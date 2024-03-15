#include <bits/stdc++.h>

using namespace std;

void out(vector<int>& ans, vector<int>& past, int t, int n) {
    int k = ans.size() - 1;
    queue<pair<int, int>> q;
    for (int i = 1, tm = t; i <= k; i++) {
        if (q.size() < n) {
            q.push({ i, past[i] + tm });
        }
        else {
            auto ft = q.front();
            ans[ft.first] = ft.second;
            q.push({ i, tm + max(ft.second, past[i]) });
            q.pop();
        }
        ans[i] = q.back().second;
    }
}

int main() {
    int k, n1, n2, n3, t1, t2, t3;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;

    vector<int> read(k + 1);
    queue<pair<int, int>> readq;
    for (int i = 1, tm = t1; i <= k; i++) {
        read[i] = tm;
        if (i % n1 == 0) tm += t1;
    }

    vector<int> rev(k + 1);
    queue<pair<int, int>> revq;
    out(rev, read, t2, n2);

    vector<int> cat(k + 1);
    queue<pair<int, int>> catq;
    out(cat, rev, t3, n3);

    cout << cat[k] << endl;
}