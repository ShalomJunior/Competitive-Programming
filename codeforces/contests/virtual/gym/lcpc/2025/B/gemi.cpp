/*
This is not my solution
*/

#include <iostream>
#include <vector>
#include <set>       // To store divisors (handles duplicates automatically)
#include <cmath>     // For sqrt()
#include <cstring>   // For memset()

// Use long long for all numerical types to avoid overflow
using ll = long long;

// --- Globals for the Digit DP State ---
// We use globals to avoid passing them in every recursive call,
// which is a common and efficient C++ competitive programming technique.

ll memo[31][2][2]; // memo[bit][tight_x][tight_y]
ll current_d;      // The current divisor d we are checking
ll current_Rx;     // The current upper bound for x (e.g., r or l-1)
ll current_Ry;     // The current upper bound for y (e.g., r or l-1)

/**
 * @brief The core Digit DP (bit-by-bit) recursive function.
 * * @param bit The current bit position we are considering (from 30 down to -1).
 * @param tight_x Is the prefix of x we've built so far equal to the prefix of current_Rx?
 * @param tight_y Is the prefix of y we've built so far equal to the prefix of current_Ry?
 * @return The number of ways to complete the suffixes of x and y.
 */
ll dfs(int bit, bool tight_x, bool tight_y) {
    // Base Case: We've successfully built a full (x, y) pair.
    if (bit == -1) {
        return 1;
    }

    // Memoization: If we've computed this state before, return the result.
    if (memo[bit][tight_x][tight_y] != -1) {
        return memo[bit][tight_x][tight_y];
    }

    ll ways = 0;

    // Determine the upper limit for the bits we can choose for x and y
    // If tight_x is true, x's bit (bx) can only go up to current_Rx's bit.
    // If tight_x is false, x is already smaller, so bx can be 0 or 1.
    int limit_x = (tight_x) ? (current_Rx >> bit) & 1 : 1;
    int limit_y = (tight_y) ? (current_Ry >> bit) & 1 : 1;

    // Get the required bit from our target divisor d
    int d_bit = (current_d >> bit) & 1;

    // Iterate over all possible choices for x's bit (bx) and y's bit (by)
    for (int bx = 0; bx <= limit_x; ++bx) {
        for (int by = 0; by <= limit_y; ++by) {

            // Primary Constraint: Check if (bx OR by) matches d's bit
            if ((bx | by) == d_bit) {

                // Determine the tightness for the next recursive call
                // new_tight_x is true only if we were tight *and* we chose the max possible bit
                bool new_tight_x = tight_x && (bx == limit_x);
                bool new_tight_y = tight_y && (by == limit_y);

                // Add the ways from the subproblem
                ways += dfs(bit - 1, new_tight_x, new_tight_y);
            }
        }
    }

    // Store the result in the memo table and return it
    return memo[bit][tight_x][tight_y] = ways;
}

/**
 * @brief Wrapper function to calculate f(d, Rx, Ry).
 * * Counts pairs (x, y) such that:
 * 1. x | y = d
 * 2. 0 <= x <= Rx
 * 3. 0 <= y <= Ry
 */
ll count_pairs(ll d, ll Rx, ll Ry) {
    // Handle the edge case for (l-1) when l=0.
    if (Rx < 0 || Ry < 0) {
        return 0;
    }

    // Set the global parameters for the dfs function
    current_d = d;
    current_Rx = Rx;
    current_Ry = Ry;

    // Clear the memoization table (initialize all to -1)
    std::memset(memo, -1, sizeof(memo));

    // Start the DP from the 30th bit (since 10^9 < 2^30)
    // We start as "tight" because we haven't chosen any bits yet.
    return dfs(30, true, true);
}

/**
 * @brief Solves a single test case.
 */
void solve() {
    ll n, l, r;
    std::cin >> n >> l >> r;

    // Step 1: Find all divisors of n
    std::set<ll> divisors;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }

    ll total_answer = 0;

    // Step 2: Iterate through each divisor d
    for (ll d : divisors) {
        // Step 3: Use the Principle of Inclusion-Exclusion
        // Count(d, [l,r], [l,r]) = f(d,r,r) - f(d,l-1,r) - f(d,r,l-1) + f(d,l-1,l-1)

        ll count_for_d = count_pairs(d, r, r);
        count_for_d -= count_pairs(d, l - 1, r);
        count_for_d -= count_pairs(d, r, l - 1);
        count_for_d += count_pairs(d, l - 1, l - 1);

        total_answer += count_for_d;
    }

    std::cout << total_answer << "\n";
}

int main() {
    // Optimize C++ standard streams for speed
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}