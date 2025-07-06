#include <bits/stdc++.h>
using namespace std;

int n;
int x[100001], y[100001];
set<pair<int, int>> comp;

// Checker functions
void check_divisor_invariant(int divisorCount, int threshold = 100) {
    if (divisorCount > threshold) {
        cerr << "Warning: High number of divisors leading to potential slowdown!" << endl;
        abort();
    }
}

void check_range_invariant(int yi, int i, int threshold = 50) {
    if (yi > threshold) {
        cerr << "Warning: Large range for divisor checks detected!" << endl;
        abort();
    }
}

void check_set_invariant(int setOperations, int threshold = 1000) {
    if (setOperations > threshold) {
        cerr << "Warning: Excessive set operations detected - potential bottleneck!" << endl;
        abort();
    }
}

int main() {
    comp.clear();
    cin >> n;
    for (int i = 0; i < (int)(n); i++) {
        cin >> x[i + 1] >> y[i + 1];
        // Check for large range
        check_range_invariant(y[i + 1], i + 1);
    }
    int totalSetOperations = 0; // Track set operations

    for (int i = 1; i <= n; i++) {
        int divisorCount = 0;
        for (int j = 1; j < 318; j++) {
            if (x[i] % j == 0) {
                comp.insert(make_pair(j, i));
                int c = x[i] / j;
                comp.insert(make_pair(c, i));
                divisorCount += 2; // Increment for both divisors j and c
            }
        }
        // Check for high number of divisors
        check_divisor_invariant(divisorCount);

        int ans = 0;
        for (int j = 1; j < 318; j++) {
            if (x[i] % j) continue;
            if (x[i] > 1 && j == x[i]) break;
            if ((long long)j * (long long)j > x[i]) break;
            set<pair<int, int>>::iterator it = comp.lower_bound(make_pair(j, i));
            ++totalSetOperations; // Count the set operation

            if (it == comp.begin())
                ans++;
            else {
                it--;
                if (it->first != j || it->second < i - y[i]) {
                    ans++;
                }
            }
            if ((long long)j * (long long)j >= x[i]) break;
            int c = x[i] / j;
            if (c == j) continue;
            it = comp.lower_bound(make_pair(c, i));
            ++totalSetOperations; // Count the set operation

            if (it == comp.begin())
                ans++;
            else {
                it--;
                if (it->first != c || it->second < i - y[i]) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    // Check for excessive set operations
    check_set_invariant(totalSetOperations);

    return 0;
}