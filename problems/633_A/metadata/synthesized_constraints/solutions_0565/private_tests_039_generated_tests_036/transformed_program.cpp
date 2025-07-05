#include <bits/stdc++.h>
using namespace std;

// Invariant checkers
void check_nearly_equal_invariant(int a, int b) {
    if (abs(a - b) <= 1) {
        cerr << "Warning: Performance bottleneck condition triggered - a and b are nearly equal!" << endl;
        abort();
    }
}

void check_high_iteration_bounds(int a, int b, int c) {
    if (c > 100 && (c % a != 0 && c % b != 0)) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration bounds!" << endl;
        abort();
    }
}

int main() {
    int a, b, c, i, j, count = 0;
    scanf("%d %d %d", &a, &b, &c);
    
    // Check for nearly equal coefficients
    check_nearly_equal_invariant(a, b);
    // Check for high iteration bounds
    check_high_iteration_bounds(a, b, c);
    
    for (i = 0; i < 10000; i++) {
        for (j = 0; j < 10000; j++) {
            if ((a * i + j * b) == c) {
                count++;
                printf("Yes");
                break;
            }
        }
        if (count > 0) break;
    }
    if (count == 0) printf("No");
    return 0;
}