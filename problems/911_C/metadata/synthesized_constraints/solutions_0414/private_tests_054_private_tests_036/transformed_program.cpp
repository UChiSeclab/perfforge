#include <bits/stdc++.h>
using namespace std;

// Checker function for overlap invariant
void check_overlap_invariant(int k1, int k2, int k3) {
    if ((k1 == k2) || (k2 == k3) || (k1 == k3)) {
        cerr << "Warning: overlap_invariant triggered - garland intervals cause high overlap!" << endl;
        abort();
    }
}

// Checker function for nested loop invariant
void check_nested_loop_invariant(int totalChecks) {
    const int threshold = 1000;
    if (totalChecks > threshold) {
        cerr << "Warning: nested_loop_invariant triggered - nested loops are trying too many combinations!" << endl;
        abort();
    }
}

// Checker function for coverage invariant
void check_coverage_invariant(bool fullCoveragePossible) {
    if (!fullCoveragePossible) {
        cerr << "Warning: coverage_invariant triggered - it's difficult to ensure full coverage!" << endl;
        abort();
    }
}

int main() {
    int Z, k1, k2, k3;
    scanf("%d%d%d", &k1, &k2, &k3);

    // Call checker for overlap invariant after reading input
    check_overlap_invariant(k1, k2, k3);

    unordered_map<int, int> MAP;
    int totalChecks = 0;
    bool fullCoveragePossible = false;

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                unordered_map<int, int> Map;
                for (int a = 0; a <= 10; a = a + k1) {
                    Map[i + a] = 1;
                }
                for (int a = 0; a <= 10; a = a + k2) {
                    Map[a + j] = 1;
                }
                for (int a = 0; a <= 10; a = a + k3) {
                    Map[a + k] = 1;
                }
                int cnt = 0;
                for (int x = 1; x <= 10; x++) {
                    if (Map[x] == 1) cnt++;
                }
                totalChecks++;
                if (cnt == 10) {
                    printf("YES\n");
                    fullCoveragePossible = true; // found a valid configuration
                    check_coverage_invariant(fullCoveragePossible);
                    return 0;
                }
            }
        }
    }
    
    // Call checker for nested loop invariant after loops
    check_nested_loop_invariant(totalChecks);

    // If we reach here, coverage was not possible
    check_coverage_invariant(fullCoveragePossible);

    printf("NO\n");
}