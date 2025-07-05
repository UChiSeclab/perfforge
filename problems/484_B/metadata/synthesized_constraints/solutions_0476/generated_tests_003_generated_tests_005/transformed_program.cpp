#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int N, a[maxn];

// Performance checker functions
void check_lower_bound_invariant(int searchCount, int threshold) {
    if (searchCount > threshold) {
        cerr << "Warning: Performance bottleneck - excessive lower_bound searches!" << endl;
        abort();
    }
}

void check_computational_load_invariant(int loopCount, int threshold) {
    if (loopCount > threshold) {
        cerr << "Warning: Performance bottleneck - high computational load in loop!" << endl;
        abort();
    }
}

void check_element_difference_invariant(int maxElement, int minElement, int elementGapThreshold) {
    if ((maxElement - minElement) > elementGapThreshold) {
        cerr << "Warning: Performance bottleneck - large differences between elements!" << endl;
        abort();
    }
}

int solve(int x) {
    int ret = 0, p = x;
    int loopCount = 0;  // Track the number of iterations in the loop
    
    while (p < maxn) {
        p += x;
        int k = lower_bound(a, a + N, p) - a;
        loopCount++; // Increment loop count for each iteration
        
        if (k == 0)
            continue;
        else
            k--;

        if (a[k] <= x) continue;
        ret = max(ret, a[k] % x);
    }

    // Check for high computational load in the loop
    check_computational_load_invariant(loopCount, 100000); // Example threshold

    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a, a + N);

    // Check for large differences between elements
    check_element_difference_invariant(a[N-1], a[0], 50000); // Example threshold

    int ans = 0;
    int searchCount = 0; // Track the number of lower_bound searches

    for (int i = N - 1; i >= 0; i--) {
        if (ans >= a[i] - 1) break;
        if (i < N - 1 && a[i] == a[i + 1]) continue;
        
        ans = max(ans, solve(a[i]));
        searchCount++;
    }

    // Check for excessive lower_bound searches
    check_lower_bound_invariant(searchCount, 1000); // Example threshold

    printf("%d\n", ans);
    return 0;
}