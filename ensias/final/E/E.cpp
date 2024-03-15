#include <bits/stdc++.h>

using namespace std;

vector<bool>visited;
vector<vector<int>> adj;

bool dfs(int i) {
    if (visited[i]) return false;
    bool ans = false;
    for (auto& child : adj[i]) {
        if (visited[child]) return true;
        dfs(child);
    }
    return false;
}


int main() {
    int n; cin >> n;

    unordered_map<string, int> num;
    visited.resize(n + 1);
    adj.resize(n + 1);
    int cnt = 0;
    for (int i = 0; i < n;i++) {
        string ei, si; cin >> ei >> si;
        int eni, sni;
        if (num.find(ei) == num.end()) eni = ++cnt;
        else eni = num[ei];
        if (num.find(si) == num.end()) sni = ++cnt;
        else sni = num[si];
        adj[eni].push_back(sni);
    }

    for (int i)


}