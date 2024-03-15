#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    stack<string> s;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        s.push(str);
    }

    unordered_map<string, bool> h;
    while (!s.empty()) {
        if (!h[s.top()]) {
            cout << s.top() << endl;
            h[s.top()] = true;
        }
        s.pop();
    }
}
