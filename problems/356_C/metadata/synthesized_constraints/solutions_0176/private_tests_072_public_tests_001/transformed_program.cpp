#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_large_compartments_invariant(int n) {
    if (n > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large number of compartments!" << endl;
        abort();
    }
}

void check_uneven_distribution_invariant(int singleton_count, int pair_count, int n) {
    if ((singleton_count + pair_count) > 0.8 * n) {
        cerr << "Warning: Performance bottleneck condition triggered due to uneven student distribution!" << endl;
        abort();
    }
}

void check_min_operations_invariant(int min_operations) {
    if (min_operations > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive adjustments!" << endl;
        abort();
    }
}

long a[1000001] = {0}, n;

int main() {
    cin >> n;
    
    // Check for large number of compartments
    check_large_compartments_invariant(n);

    long long sum = 0;
    sort(a + 1, a + n + 1);
    for (int k = 1; k <= n; ++k) cin >> a[k], sum += a[k];
    if (sum == 1 || sum == 2 || sum == 5) {
        cout << -1;
        return 0;
    }

    long s = 0, s1 = 0, s2 = 0, s3 = 0;
    sum = 0;
    for (int k = 1; k <= n; ++k)
        if (a[k] == 1)
            ++s;
        else if (a[k] == 2)
            ++s1;
        else if (a[k] == 3)
            ++s3;
        else if (a[k] == 4)
            s2++;

    // Check for uneven distribution of students
    check_uneven_distribution_invariant(s, s1, n);

    s3 += min(s, s1);
    sum += min(s, s1);
    s1 = s1 - s;

    // Check for excessive min operations
    check_min_operations_invariant(sum);

    if (s1 < 0)
        s = -s1, s1 = 0;
    else
        s = 0;
    if (s > 0) {
        sum += s - s / 3;
        if (s == 1 && s3 == 0) ++sum;
    }
    if (s1 > 0) {
        sum += s1 - s1 / 3;
        if (s1 % 3 == 1 && s2 == 0) ++sum;
    }
    cout << sum;
    return 0;
}