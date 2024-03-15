#include <bits/stdc++.h>
#define mine pair<int,int>
#define F first
#define S second
using namespace std;

mine read() {
    mine ans;
    char c; int hs, ms, he, me;
    cin >> hs >> c >> ms >> c >> he >> c >> me;
    ans.F = hs * 60 + ms;
    ans.S = he * 60 + me;
    return ans;
}

vector<mine> perform() {
    vector<mine> temp;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        temp.push_back(read());

    sort(temp.begin(), temp.end());

    vector<mine> ans;
    int L = temp[0].F, R = temp[0].S;
    for (int i = 1; i < n; i++) {
        if (temp[i].F <= R + 1) R = max(R, temp[i].S);
        else {
            temp.push_back({ L,R });
            L = temp[i].F;
            R = temp[i].S;
        }
    }
    ans.push_back({ L, R });
    return ans;
}

void solve() {
    priority_queue<mine> pq;
    int p = 2;
    while (p--) {
        auto f = perform();
        for (auto& [k, v] : f) pq.push({ -k, -v });
    }

    priority_queue<int> out;
    for (int i = 0; i < 1440; i++) {
        while (!pq.empty() && -pq.top().F <= i) {
            out.push(pq.top().S);
            pq.pop();
        }
        while (!out.empty() && -out.top() < i) out.pop();
        if (out.size() > 1 && -out.top() - i + 1 >= 30) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}