#include <bits/stdc++.h>
using namespace std;

// Functions to check the performance invariants
void check_low_probability_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to low probabilities triggered!" << endl;
        abort();
    }
}

void check_complementary_probability_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to high complementary probabilities triggered!" << endl;
        abort();
    }
}

int main() {
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    
    double ps = a / b, pz = c / d, pw = 0;
    double nps = 1 - ps, npz = 1 - pz;
    
    // Performance invariant check 1:
    // Detect low shooting probabilities leading to slow computations
    check_low_probability_invariant(ps < 0.01 && pz < 0.01);
    
    // Performance invariant check 2:
    // Detect high complementary probabilities leading to many loop iterations
    check_complementary_probability_invariant(nps > 0.99 && npz > 0.99);

    for (int i = 0;; i++) {
        double k = pow(nps, i) * pow(npz, i) * ps;
        pw += k;
        if (k < 0.0000000000001) break;
    }
    printf("%.12f", pw);
}