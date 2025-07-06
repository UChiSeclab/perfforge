#include <bits/stdc++.h>
using namespace std;

// Check if the greatest common divisor of a and b does not divide c
void check_gcd_invariant(int a, int b, int c) {
    if (c % __gcd(a, b) != 0) {
        cerr << "Warning: gcd_invariant triggered - gcd(a, b) does not divide c" << endl;
        abort();
    }
}

// Check if a and b are close and neither is a direct divisor of c
void check_close_values_invariant(int a, int b, int c) {
    if (abs(a - b) <= 5 && c % a != 0 && c % b != 0) {
        cerr << "Warning: close_values_invariant triggered - a and b are close, and neither divides c" << endl;
        abort();
    }
}

// Check if c cannot be easily formed by small multiples of a and b
void check_large_iterations_invariant(int a, int b, int c) {
    if (c > 1000 && c > max(a, b) * 10) {
        cerr << "Warning: large_iterations_invariant triggered - c is not easily formed by small multiples of a or b" << endl;
        abort();
    }
}

int main() {
    int a, b, c, x, y;
    int p, flag = 0;
    scanf("%d %d %d", &a, &b, &c);
    
    // Place the checks after reading inputs, before heavy loops
    check_gcd_invariant(a, b, c);
    check_close_values_invariant(a, b, c);
    check_large_iterations_invariant(a, b, c);
    
    for (x = 0; x <= 10000; x++) {
        for (y = 0; y <= 10000; y++) {
            p = x * a + y * b;
            if (p == c) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    if (flag == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}