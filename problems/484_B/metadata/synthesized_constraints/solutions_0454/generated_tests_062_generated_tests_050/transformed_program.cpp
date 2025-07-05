#include <bits/stdc++.h>
using namespace std;

int A[200010];

void check_small_value_invariant(int smallestElement) {
    if (smallestElement < 10) {
        cerr << "Warning: Performance bottleneck triggered due to small array element!" << endl;
        abort();
    }
}

void check_lower_bound_invariant(int lowerBoundCalls, int threshold) {
    if (lowerBoundCalls > threshold) {
        cerr << "Warning: Performance bottleneck triggered due to frequent lower_bound calls!" << endl;
        abort();
    }
}

void check_iterations_invariant(int iterations, int maxIterations) {
    if (iterations > maxIterations) {
        cerr << "Warning: Performance bottleneck triggered due to too many loop iterations!" << endl;
        abort();
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A, A + N);
    N = unique(A, A + N) - A;

    // Check for small element invariant
    check_small_value_invariant(A[0]);  // Assuming A is non-empty and sorted

    int ma = 0;
    int lowerBoundCalls = 0;

    for (int i = 0; i < N; ++i) {
        int iterations = 0;
        for (int j = A[i]; j <= 1000000; j += A[i]) {
            int f = j, s = j + A[i];
            int p = lower_bound(A + i + 1, A + N, s) - A;
            lowerBoundCalls++;

            if (p == 0) continue;
            p--;
            ma = max(ma, A[p] - f);
            iterations++;
        }

        // Check for iteration invariant within this loop
        check_iterations_invariant(iterations, 100000);  // Arbitrary max iterations for a single element
    }

    // Check for frequent lower_bound calls invariant
    check_lower_bound_invariant(lowerBoundCalls, 100000);  // Arbitrary threshold for total calls

    cout << ma << endl;
}