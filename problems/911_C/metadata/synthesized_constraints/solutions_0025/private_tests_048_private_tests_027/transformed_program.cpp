#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long long int MOD = 1000000007;
const long double EPS = 1e-9;

// Checker functions
void check_nesting_invariant(int iterations) {
    if (iterations > 1000000) {
        cerr << "Warning: High nesting level detected - excessive iterations in nested loops!" << endl;
        abort();
    }
}

void check_array_update_invariant(int k1, int k2, int k3) {
    if (k1 > 500 && k2 > 500 && k3 > 500) {
        cerr << "Warning: Array update invariant triggered - excessive updates to the array!" << endl;
        abort();
    }
}

void check_interval_overlap_invariant(int k1, int k2, int k3) {
    if (k1 > 1000 || k2 > 1000 || k3 > 1000) {
        cerr << "Warning: Interval overlap invariant triggered - insufficient overlap between garland timings!" << endl;
        abort();
    }
}

void check_input_sensitivity_invariant(int k1, int k2, int k3) {
    if (abs(k1 - k2) < 10 && abs(k2 - k3) < 10 && abs(k1 - k3) < 10) {
        cerr << "Warning: Input sensitivity invariant triggered - intervals too close!" << endl;
        abort();
    }
}

int main() {
    int k1, k2, k3;
    bool light[101];
    scanf("%d %d %d\n", &k1, &k2, &k3);
    
    // Insert checks based on invariants
    check_array_update_invariant(k1, k2, k3);
    check_interval_overlap_invariant(k1, k2, k3);
    check_input_sensitivity_invariant(k1, k2, k3);
    
    int nestingIterations = 0;
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int p = 1; p <= 100; p++) {
                nestingIterations++;
                
                // Check nesting level invariant
                check_nesting_invariant(nestingIterations);
                
                for (int z = 1; z <= 100; z++) {
                    light[z] = false;
                }
                for (int z = i; z <= 100; z += k1) {
                    light[z] = true;
                }
                for (int z = j; z <= 100; z += k2) {
                    light[z] = true;
                }
                for (int z = p; z <= 100; z += k3) {
                    light[z] = true;
                }
                bool finish = true;
                for (int z = 1; z <= 100; z++) {
                    if (!light[z]) {
                        finish = false;
                        break;
                    }
                }
                if (finish) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}