#include <bits/stdc++.h>
using namespace std;

// Checker for equal damage values
void check_equal_damage_invariant(int a, int b) {
    if (a == b) {
        cerr << "Warning: Performance bottleneck condition triggered! Equal damage values." << endl;
        abort();
    }
}

// Checker for small c relative to a and b
void check_small_c_invariant(int a, int b, int c) {
    if (c < a && c < b) {
        cerr << "Warning: Performance bottleneck condition triggered! Small c relative to a and b." << endl;
        abort();
    }
}

// Checker for situations likely to cause exhaustive search
void check_exhaustive_search_invariant(int a, int b, int c) {
    if ((a <= 10 && b <= 10 && c >= 100) || (c % a != 0 && c % b != 0)) {
        cerr << "Warning: Performance bottleneck condition triggered! Exhaustive search likely." << endl;
        abort();
    }
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    // Run the performance checkers
    check_equal_damage_invariant(a, b);
    check_small_c_invariant(a, b, c);
    check_exhaustive_search_invariant(a, b, c);

    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (a * i + b * j == c) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}