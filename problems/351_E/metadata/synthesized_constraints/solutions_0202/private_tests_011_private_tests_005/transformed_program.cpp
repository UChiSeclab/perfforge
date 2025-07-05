#include <bits/stdc++.h>
using namespace std;

// Function definitions for performance checkers
// Placed here as they relate to input characteristics and sequence properties

// Check if the initial sequence has too many inversions
void check_initial_inversion_invariant(int inversions, int n) {
    if (inversions > (n * (n - 1)) / 4) { // Arbitrary threshold based on average-case half of total possible inversions
        cerr << "Warning: Performance bottleneck condition triggered due to initial inversion count!" << endl;
        abort();
    }
}

// Check if the sequence has many elements that are potential candidates for flipping
void check_flipping_candidate_invariant(int n, const int* a) {
    int potentialFlips = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0 && ((i > 0 && a[i-1] * a[i] < 0) || (i < n-1 && a[i] * a[i+1] < 0))) {
            potentialFlips++;
        }
    }
    if (potentialFlips > n / 2) { // If more than half the elements are candidates for flipping
        cerr << "Warning: Performance bottleneck condition triggered due to potential flip candidates!" << endl;
        abort();
    }
}

// Check frequent satisfaction of conditions during inversion adjustments
void check_condition_satisfaction_invariant(int n, const int* a) {
    int conditionCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (((j < i && a[j] > a[i] && a[j] <= -a[i]) ||
                 (j < i && a[j] <= a[i] && a[j] > -a[i]) ||
                 (i < j && a[i] <= a[j] && -a[i] > a[j]) ||
                 (i < j && a[i] > a[j] && -a[i] <= a[j]))) {
                conditionCount++;
            }
        }
    }
    if (conditionCount > n * n / 4) { // If conditions are triggered more than a quarter of total checks
        cerr << "Warning: Performance bottleneck condition triggered due to frequent condition satisfaction!" << endl;
        abort();
    }
}

int main() {
    int n, a[2048];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j < i && a[j] > a[i])
                ++ans;
            else if (j > i && a[j] < a[i])
                ++ans;
        }
    }
    
    // Check initial inversion invariant after counting inversions
    check_initial_inversion_invariant(ans, n);
    
    for (int i = 0; i < 10; ++i) {
        for (int i = 0; i < n; ++i) {
            int k = 0;
            for (int j = 0; j < n; ++j) {
                if (j < i && a[j] > a[i] && a[j] <= -a[i])
                    --k;
                else if (j < i && a[j] <= a[i] && a[j] > -a[i])
                    ++k;
                else if (i < j && a[i] <= a[j] && -a[i] > a[j])
                    ++k;
                else if (i < j && a[i] > a[j] && -a[i] <= a[j])
                    --k;
            }

            // Check condition satisfaction invariant each time through the loop
            check_condition_satisfaction_invariant(n, a);

            if (k <= 0) {
                a[i] = -a[i];
                ans += 2 * k;
            }
        }
    }
    
    // Check flipping candidate invariant after processing adjustments
    check_flipping_candidate_invariant(n, a);
    
    printf("%d\n", ans / 2);
    return 0;
}