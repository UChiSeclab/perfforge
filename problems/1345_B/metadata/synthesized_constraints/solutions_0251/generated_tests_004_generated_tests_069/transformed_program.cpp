#include <bits/stdc++.h>
using namespace std;

// Maximum bounds as described in the problem statement
const long long MAX_N = 1000000000;
const long long ITERATION_THRESHOLD = 100000; // Adjusted based on observed bottleneck behavior

// Check if n is close to its maximum, inducing potential long precomputation
void check_large_n_invariant(long long maximum_n, long long current_n) {
    if (current_n > maximum_n * 0.9) {  // Check if n is close to the maximum possible value
        cerr << "Warning: Performance bottleneck condition triggered due to large n!" << endl;
        abort();
    }
}

// Check for excessive iterations in the precomputation loop
void check_excessive_iteration_invariant(long long iteration_count, long long threshold) {
    if (iteration_count > threshold) {  // Check if iteration count exceeds a certain threshold
        cerr << "Warning: Performance bottleneck condition triggered due to excessive iterations!" << endl;
        abort();
    }
}

int main() {
    long int t, i;
    cin >> t;
    long int arr[t];
    for (i = 0; i < t; i++) cin >> arr[i];
    long int m = *max_element(arr, arr + t);
    
    // Check if the maximum n is close to the upper constraint
    check_large_n_invariant(MAX_N, m);
    
    vector<long long int> brr;
    brr.push_back(2);
    i = 1;
    long long iteration_count = 0;
    
    while (1) {
        brr.push_back(brr[i - 1] + 3 * i + 2);
        if (brr[i] > m) break;
        i++;
        iteration_count++;
        
        // Check for excessive iterations
        check_excessive_iteration_invariant(iteration_count, ITERATION_THRESHOLD);
    }
    
    for (i = 0; i < t; i++) {
        long int a = arr[i];
        long int c = 0;
        while (a) {
            auto it = upper_bound(brr.begin(), brr.end(), a);
            if (it == brr.begin()) break;
            c++;
            it--;
            a = a - *it;
        }
        cout << c << endl;
    }
}