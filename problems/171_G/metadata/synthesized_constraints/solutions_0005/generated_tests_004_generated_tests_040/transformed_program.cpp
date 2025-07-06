#include <bits/stdc++.h>
using namespace std;

int a, b;

void check_recursion_invariant(int c) {
    if (c >= 20) { // Recursion depth check
        cerr << "Warning: Recursion depth invariant triggered - excessive recursion depth" << endl;
        abort();
    }
}

void check_computation_redundancy(int c) {
    if (c >= 20) { // Computation redundancy check
        cerr << "Warning: Computation redundancy invariant triggered - redundant calculations" << endl;
        abort();
    }
}

int fonk(int c) {
    check_recursion_invariant(c); // Check before recursion
    check_computation_redundancy(c); // Check for redundant computations
    
    if (c == 0) return a;
    if (c == 1) return b;
    return fonk(c - 1) + fonk(c - 2);
}

int main() {
    int c;
    scanf("%d %d", &a, &b);
    scanf("%d", &c);

    printf("%d", fonk(c));
    return 0;
}