#include <iostream>
using namespace std;

int n, m, x, r, i, j;

// Checker function for nested loop invariant
void check_nested_loop_invariant(int n, int m, int x) {
    if ((m - 2 * x + 1) > 1000) { // Threshold based on observed performance
        cerr << "Warning: Performance bottleneck condition triggered - Inner loop executes extensively." << endl;
        abort();
    }
}

// Checker function for condition evaluation invariant
void check_condition_evaluation_invariant(int n, int m, int x) {
    if ((m - 2 * x + 1) * (n - 2 * x + 1) > 1000000) { // Threshold for high condition checks
        cerr << "Warning: Performance bottleneck condition triggered - Condition evaluations dominate execution." << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &x);
    
    // Insert checker function call after input is read
    check_nested_loop_invariant(n, m, x);
    check_condition_evaluation_invariant(n, m, x);

    for (i = x; i <= n - x + 1; i++) {
        for (j = x; j <= m - x + 1; j++) {
            if (((i + j) & 1) == 0 &&
                (i == x || i == n - x + 1 || j == x || j == m - x + 1)) {
                r++;
            }
        }
    }
    printf("%d\n", r);
    return 0;
}