#include <bits/stdc++.h>
using namespace std;

// Performance invariant check functions
void check_modulo_invariant(long long a, long long m, long long iteration_limit) {
    if (iteration_limit > 10000000) {  // Example arbitrary large threshold
        cerr << "Warning: Modulo invariant triggered - excessive iterations without termination" << endl;
        abort();
    }
}

void check_increment_invariant(long long a, long long m, long long x) {
    if (x == 0) {  // If x becomes 0, the increment won't change a
        cerr << "Warning: Increment invariant triggered - stagnation due to zero increment" << endl;
        abort();
    }
}

void check_large_initial_values_invariant(long long a, long long m) {
    if (a > 90000 && m > 90000) {  // Thresholds near the maximum constraints
        cerr << "Warning: Large initial values invariant triggered - potential inefficiency with large a and m" << endl;
        abort();
    }
}

int main() {
    long long a, m;
    cin >> a >> m;

    // Check large initial values invariant
    check_large_initial_values_invariant(a, m);

    long long MAX = a + 9999997;
    long long cnt = 0;
    while (cnt <= MAX) {
        long long x = a % m;

        // Check increment invariant
        check_increment_invariant(a, m, x);

        if ((x + a) % m == 0) {
            cout << "Yes" << endl;
            return 0;
        } else {
            a += x;
        }
        cnt++;

        // Check modulo invariant
        check_modulo_invariant(a, m, cnt);
    }
    cout << "No" << endl;
    return 0;
}