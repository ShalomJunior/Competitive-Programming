#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<unordered_map<int, int>> db;
    string line;

    int i = 0;
    while (getline(cin, line)) {
        db.push_back(unordered_map<int, int>());
        istringstream iss(line);
        int num;
        while (iss >> num) db[i][num]++;
        i++;
    }

    for (int j = 0; j < i - 1; j++) {
        int cnt = 0;
        for (auto& [k, v] : db[j]) {
            if (db[j + 1][k] == 0) cnt += v;
        }
        cout << cnt << endl;
    }
}