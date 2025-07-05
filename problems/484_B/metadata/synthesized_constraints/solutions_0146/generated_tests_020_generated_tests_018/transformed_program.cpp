#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void check_lower_bound_invariant(int iterationCount, int threshold) {
    if (iterationCount > threshold) {
        cerr << "Warning: High frequency of lower bound searches detected!" << endl;
        abort();
    }
}

void check_remainder_invariant(int divisor, int threshold) {
    if (divisor > threshold) {
        cerr << "Warning: Extensive remainder calculations with large divisor!" << endl;
        abort();
    }
}

void check_loop_multiplier_invariant(int multiplier, int threshold) {
    if (multiplier > threshold) {
        cerr << "Warning: Large loop multiplier causing excessive iterations!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int lim = 1000000;
    int ans = -1;

    // Check before the loop starts
    check_loop_multiplier_invariant(v.back(), 100000);  // check if largest number is too high

    for (int i = 0; i < n; i++) {
        if (i > 0 and v[i] == v[i - 1]) continue;
        int cur = 2 * v[i];
        int iterationCount = 0; // To track iterations for the lower_bound search

        while (1) {
            iterationCount++;
            auto it = lower_bound(v.begin(), v.end(), cur - 1);
            if (it == v.end()) {
                ans = max(ans, v[n - 1] % v[i]);
            } else {
                if (*it == cur - 1)
                    ans = max(ans, *(it) % v[i]);
                else
                    ans = max(ans, *(--it) % v[i]);
            }

            // Check for high frequency of lower bound searches
            check_lower_bound_invariant(iterationCount, 50000);  // arbitrary but reasonable threshold

            if (cur > lim) break;
            cur += v[i];

            // Check for large divisor in remainder calculations
            check_remainder_invariant(v[i], 100000);  // arbitrary threshold
        }
    }
    cout << ans << endl;
    return 0;
}