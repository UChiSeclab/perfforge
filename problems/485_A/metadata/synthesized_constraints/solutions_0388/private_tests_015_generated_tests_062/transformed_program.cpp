#include <bits/stdc++.h>

// Check function for large remainder space
void check_large_remainder_space(bool condition) {
    if (condition) {
        cerr << "Warning: Large remainder space - potential slowdown due to many unique remainders." << endl;
        abort();
    }
}

// Check function for high iteration count in while loop
void check_high_while_iterations(bool condition) {
    if (condition) {
        cerr << "Warning: High iteration count in while loop - potential performance bottleneck." << endl;
        abort();
    }
}

// Check function for repeated remainders
void check_remainder_repetition(bool condition) {
    if (condition) {
        cerr << "Warning: Repeated remainders detected - may cause exponential growth in checks." << endl;
        abort();
    }
}

int main() {
    int a, m, mod, j = 0;
    scanf("%d%d", &a, &m);
    int b[m];

    // Invariant checks for pre-loop conditions
    check_large_remainder_space(m > 1000); // Arbitrary threshold for large m

    int iteration_count = 0;
    while (a % m != 0) {
        mod = a % m;

        // Invariant check for high iteration in while loop
        check_high_while_iterations(iteration_count > 100000); // Threshold for iteration count
        iteration_count++;

        for (int i = 0; i < j; ++i) {
            if (b[i] == mod) {
                // Invariant check for remainder repetition detection
                check_remainder_repetition(true); // This is the situation we're checking for
                printf("No");
                return 0;
            }
        }
        b[j] = mod;
        j++;
        a += mod;
    }
    printf("Yes");
    return 0;
}