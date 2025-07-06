#include <bits/stdc++.h>
using namespace std;

int n, m;

// Check for large m
void check_large_m_invariant(int m) {
    if (m > 100000) { // Choose a reasonable threshold based on performance limits
        cerr << "Warning: Performance bottleneck condition triggered due to large 'm'!" << endl;
        abort();
    }
}

// Check for excessive loop iterations due to conditional branching
void check_conditional_branching_invariant(int m, int loopIterations) {
    if (m > 100000 && loopIterations > 100000) { // Example threshold values
        cerr << "Warning: Performance bottleneck condition triggered by excessive loop iterations and conditional branching!" << endl;
        abort();
    }
}

// Check for large binary search range
void check_binary_search_invariant(int l, int r) {
    if ((r - l) > 1000000) { // If the search space is too large
        cerr << "Warning: Performance bottleneck condition triggered by large binary search range!" << endl;
        abort();
    }
}

bool check(int x) {
    int num = (x - 2 * n) / 2, tmp = m, top = 0;
    int loopIterations = 0; // Track loop iterations for conditional check

    while (tmp > 0) {
        top += 3;
        if (top % 6 == 0) {
            if (num > 0)
                num--;
            else
                top += 3;
        }
        tmp--;
        loopIterations++;
    }

    // Check conditional branching and loop iterations
    check_conditional_branching_invariant(m, loopIterations);

    return top <= x;
}

int main() {
    scanf("%d%d", &n, &m);

    // Check for large m
    check_large_m_invariant(m);

    int l = max(2 * n, 3 * m), r = 6000000, mid;

    // Check for large binary search range
    check_binary_search_invariant(l, r);

    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid) == true)
            r = mid;
        else
            l = mid + 1;

        // Update and check binary search range during iteration
        check_binary_search_invariant(l, r);
    }

    printf("%d", l);
    return 0;
}