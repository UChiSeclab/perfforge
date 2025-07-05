#include <bits/stdc++.h>
using namespace std;

void check_initial_relationship(long long a, long long m) {
    if (a < m && a % m != 0 && (a + (a % m)) % m != 0) {
        cerr << "Warning: Initial relationship suggests potential slow convergence!" << endl;
        abort();
    }
}

void check_modulus_effect(long long a, long long m) {
    if (m > 1 && a < 2 * m && a % m != 0) {
        cerr << "Warning: Modulus effect might cause slow convergence!" << endl;
        abort();
    }
}

void check_iteration_convergence(long long a, long long m) {
    if (m > 1 && a % m == 0) {
        cerr << "Warning: Immediate convergence detected, no iterations needed!" << endl;
        abort();
    }
}

int main() {
    long long int a, m;
    cin >> a >> m;

    // Insert checks here to detect potential performance issues based on identified invariants
    check_initial_relationship(a, m);
    check_modulus_effect(a, m);
    check_iteration_convergence(a, m);

    for (int i = 0; i < 1e7; i++) {
        if (a % m == 0) {
            puts("Yes");
            return 0;
        }
        a = a + (a % m);
    }
    puts("No");
    return 0;
}