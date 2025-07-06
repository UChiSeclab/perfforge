#include <bits/stdc++.h>
using namespace std;

// Checker for small `m` relative to pyramid sizes
void check_small_m_invariant(long long m, long long largestPyramidSize) {
    if (m < largestPyramidSize / 10) {
        cerr << "Warning: Inefficient check - m is too small relative to pyramid size" << endl;
        abort();
    }
}

// Checker for excessive loop iterations
void check_pyramid_construction_invariant(long long loopCounter, long long maxIterations) {
    if (loopCounter > maxIterations) {
        cerr << "Warning: Performance bottleneck - excessive loop iterations for decrement" << endl;
        abort();
    }
}

// Checker for multiple small test cases
void check_multiple_small_cases(int countOfSmallCases, int threshold) {
    if (countOfSmallCases > threshold) {
        cerr << "Warning: Multiple small cases detected" << endl;
        abort();
    }
}

long long p[100000];

int main() {
    for (long long i = 1; i < 100000; i++) {
        p[i] = i * i + ((i + 1) * i) / 2;
    }
    
    int n, countOfSmallCases = 0, smallThreshold = 50; // set threshold as needed
    cin >> n;
    
    while (n--) {
        long long m, cnt = 0;
        cin >> m;

        // Check if `m` is small relative to the largest pyramid size
        check_small_m_invariant(m, p[99999]);

        long long loopCounter = 0;
        for (long long i = 100000 - 1; i >= 1; i--) {
            loopCounter++;
            if (p[i] <= m) {
                m -= p[i];
                cnt++;
                i++;
            }
        }

        // Check for excessive loop iterations
        check_pyramid_construction_invariant(loopCounter, 500000); // arbitrary max iterations

        // Track small cases
        if (m < 100) {
            countOfSmallCases++;
        }

        printf("%lld\n", cnt);
    }
    
    // Check for multiple small cases
    check_multiple_small_cases(countOfSmallCases, smallThreshold);

    return 0;
}