#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// May be should handle n = 2 case (if got wrong answer)
void solve()
{
    int N;
    cin >> N;
    printf("%.9f\n", 1.0 / tan(M_PI / N));
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        solve();
}