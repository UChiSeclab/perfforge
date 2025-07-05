#include <bits/stdc++.h> 
using namespace std;

// Function to check for high iteration invariant
void check_high_iteration_invariant(int n) {
    if (n > 1000) { // Arbitrary threshold based on problem constraints
        cerr << "Warning: high_iteration_invariant triggered - n is large, causing many loop iterations" << endl;
        abort();
    }
}

// Function to check for bottleneck in nested loops
void check_bottleneck_invariant(int b) {
    if (b > 2000) { // Arbitrary threshold considering the maximum of 5000
        cerr << "Warning: bottleneck_invariant triggered - large bottle count, causing excessive loop nesting" << endl;
        abort();
    }
}

// Function to check for excessive array updates
void check_array_update_invariant(int totalIterations) {
    if (totalIterations > 1000000) { // Total iterations measure
        cerr << "Warning: array_update_invariant triggered - excessive array updates in loops" << endl;
        abort();
    }
}

int main() {
    int n, m, i, j, k, sum;
    int a[5] = {1, 2, 4}, b;
    int c1[20005], c2[20005];

    while (scanf("%d", &n) != EOF) {
        check_high_iteration_invariant(n); // Check for high iteration

        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        c1[0] = 1;

        int totalIterations = 0; // Track total iterations

        for (i = 0; i < 3; i++) {
            scanf("%d", &b);
            check_bottleneck_invariant(b); // Check for bottleneck

            for (j = 0; j <= 2 * n; j++) {
                for (k = 0; k <= b && j + a[i] * k <= 2 * n; k++) {
                    c2[j + a[i] * k] += c1[j];
                    totalIterations++;
                }
            }

            for (j = 0; j <= 2 * n; j++) {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }

        check_array_update_invariant(totalIterations); // Check for excessive updates
        printf("%d\n", c1[2 * n]);
    }

    return 0;
}