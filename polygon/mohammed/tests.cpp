#include "testlib.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1); // Initialize the generator with command-line arguments

    int test_count = opt<int>("test-count"); // Number of test cases
    int sum_n = opt<int>("sum-n"); // Total sum of lengths of all arrays
    int min_n = opt<int>("min-n", 1); // Minimum length of each array

    int min_value = opt<int>("min-value", 1); // Minimum value for array elements
    int max_value = opt<int>("max-value", 1000000); // Maximum value for array elements

    // Generate a list of lengths for each test case, ensuring sum_n total length
    vector<int> n_list = rnd.partition(test_count, sum_n, min_n);
    println(test_count);

    for (int i = 0; i < test_count; ++i) {
        cerr << "i  =" << i << endl;
        int n = n_list[i]; // Length of the array for this test case
        int m = rnd.next(1, 1000000); // Mohammed's chosen integer
        println(n, m);
        vector<int> a(n);
        // Generate array elements
        for (int j = 0; j < n; ++j) {
            int value = rnd.next(min_value, max_value);
            a[j] = value;
        }
        println(a);
    }
    return 0;
}
