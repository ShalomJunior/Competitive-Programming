#include <bits/stdc++.h>
using namespace std;

int main () {
    int ncols;
    cin >> ncols;
    vector<vector<int>> grid (2, vector<int>(ncols));
    for (int i = 0; i < ncols; ++ i)
        cin >> grid [0][i];
    for (int i = 0; i < ncols; ++ i)
        cin >> grid [1][i];
}
