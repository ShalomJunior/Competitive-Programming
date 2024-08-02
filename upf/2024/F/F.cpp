#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> after;
    int start = 0;
    for (int i = 1; i <= n; i++) {
        int front;
        cin >> front;
        if (front == -1) start = i;
        else after[front] = i;
    }
    int cnt = 0;
    while (cnt < n) {
        cout << start << " ";
        start = after[start];
        cnt++;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}