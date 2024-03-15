#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n1, n2, n3, t1, t2, t3;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2;
    queue<pair<int, int>> read, rev, cat;
    for (int i = 1; i <= k; i++)
        read.push({ i, t1 });


    int t = 0;
    while (!read.empty() || !rev.empty() || !cat.empty()) {
        t++;
        if (!read.empty()) {
            if (read.front().second == 0) {
                int cnt = n1;
                while (cnt > 0 && !read.empty()) {
                    rev.push({ read.front().first, t2 });
                    read.pop();
                    cnt--;
                }
            }
            else read.front().second--;
        }

        if (!rev.empty()) {
            if (rev.front().second == 0) {
                int cnt = n2;
                while (cnt > 0 && !rev.empty()) {
                    cat.push({ rev.front().first, t3 });
                    rev.pop();
                    cnt--;
                }
            }
            else rev.front().second--;
        }

        if (!cat.empty()) {
            if (cat.front().second == 0) {
                int cnt = n3;
                while (cnt > 0 && !cat.empty()) {
                    cat.pop();
                    cnt--;
                }
            }
            else cat.front().second--;
        }
    }

    cout << t << endl;
}