#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_high_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count in nested loops!" << endl;
        abort();
    }
}

void check_similar_steps_invariant(int a, int c) {
    if (abs(a - c) < 5) {
        cerr << "Warning: Performance bottleneck condition triggered - similar incremental steps!" << endl;
        abort();
    }
}

void check_initial_offset_difference(int b, int d) {
    if (abs(b - d) > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - large initial offset difference!" << endl;
        abort();
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Insert invariant checks at logical places
    check_similar_steps_invariant(a, c); // Check for similar step increments
    check_initial_offset_difference(b, d); // Check for large initial offset difference

    int iteration_count = 0; // Track iteration count for high iteration check

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            iteration_count++;
            if (j * c == b - d + i * a) {
                cout << b + a * i;
                return 0;
            }
        }
    }

    // Assess if too many iterations occurred
    check_high_iteration_invariant(iteration_count > 1000000); // Example threshold 

    cout << "-1" << endl;
    return 0;
}