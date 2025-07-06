#include <bits/stdc++.h>
using namespace std;

// Check for excessive iteration count
void check_iteration_invariant(int i) {
    if (i >= 1e6) {  // Set a threshold to detect excessive iterations
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count!" << endl;
        abort();
    }
}

// Check for excessive popcount mismatches
void check_popcount_invariant(long long m, int i) {
    if (__builtin_popcountll(m) > i) {  // Check if the popcount is frequently larger than 'i'
        cerr << "Warning: Performance bottleneck condition triggered - excessive popcount mismatches!" << endl;
        abort();
    }
}

int main() {
    long long n, p;
    cin >> n >> p;

    for (int i = 1; i < 1e7; i++) {
        long long m = n - p * i;

        // Check the iteration invariant before proceeding further
        check_iteration_invariant(i);

        // Check the popcount invariant for each iteration
        check_popcount_invariant(m, i);

        if (m >= i && __builtin_popcountll(m) <= i) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}