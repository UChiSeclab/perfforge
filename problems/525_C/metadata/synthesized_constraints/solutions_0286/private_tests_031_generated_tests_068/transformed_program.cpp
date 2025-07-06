#include <bits/stdc++.h>
using namespace std;

long long a[1000010];
long long h[1000010];

void check_iteration_range_invariant(long long range) {
    if (range > 1000) {  // Arbitrary threshold
        cerr << "Warning: iteration_range_invariant triggered - excessive loop iterations due to large max-min range" << endl;
        abort();
    }
}

void check_condition_frequency_invariant(int oddCountChecks) {
    if (oddCountChecks > 500) {  // Arbitrary threshold
        cerr << "Warning: condition_frequency_invariant triggered - frequent condition checks slowing execution" << endl;
        abort();
    }
}

void check_skewed_distribution_invariant(bool skewed) {
    if (skewed) {
        cerr << "Warning: skewed_distribution_invariant triggered - skewed stick length distribution" << endl;
        abort();
    }
}

int main() {
    long long n, x, max = -1, min = 1e9;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
        h[a[i]]++;
    }

    // Check for large iteration range
    long long range = max - min;
    check_iteration_range_invariant(range);

    // Check for skewed distribution of sticks
    bool skewed = false;
    for (long long i = max; i >= min; i--) {
        if (h[i] > 1000) {  // Arbitrary threshold for "frequent"
            skewed = true;
            break;
        }
    }
    check_skewed_distribution_invariant(skewed);

    int oddCountChecks = 0;
    for (long long i = max; i >= min; i--) {
        if (h[i] % 2) {
            if (h[i - 1]) {
                h[i - 1]++;
            }
            h[i]--;
            oddCountChecks++;  // Count how often the condition is true
        }
    }
    // Check for frequent condition checking
    check_condition_frequency_invariant(oddCountChecks);

    long long area = 0;
    long long flag = 0, temp;
    for (long long i = max; i >= min; i--) {
        if (h[i]) {
            if (flag) {
                area += i * temp;
                h[i] -= 2;
            }
            long long f = h[i] / 4;
            area += f * (i * i);
            h[i] %= 4;
            if (h[i] == 2) {
                flag = 1;
                temp = i;
            } else
                flag = 0;
        }
    }
    cout << area << endl;
    return 0;
}