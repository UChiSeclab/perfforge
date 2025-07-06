#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_frequent_calls_invariant(int calls, int threshold) {
    if (calls > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent calls to closest_sq!" << endl;
        abort();
    }
}

void check_zero_candies_invariant(int zeroCount, int threshold) {
    if (zeroCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many zero candies needing conversion!" << endl;
        abort();
    }
}

void check_input_size_invariant(int n, int threshold) {
    if (n > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large input size!" << endl;
        abort();
    }
}

void check_imbalance_invariant(int sq, int notSq, int half) {
    if (abs(sq - notSq) > half) {
        cerr << "Warning: Performance bottleneck condition triggered - significant imbalance between squares and non-squares!" << endl;
        abort();
    }
}

long long closest_sq(long long num) {
    double sqrt_ = sqrt(num);
    int a1 = int(sqrt_);
    int a2 = int(sqrt_) + 1;
    long long ans1 = a1 * a1;
    long long ans2 = a2 * a2;
    if (num - ans1 > ans2 - num) {
        return ans2;
    } else {
        return ans1;
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<long long> a(n);
        vector<long long> d;
        int sq = 0;
        int not_sq = 0;
        int zeros = 0;
        int closestCalls = 0;

        check_input_size_invariant(n, 100000);  // Check large input

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0) {
                zeros++;
            } else {
                long long closest = closest_sq(a[i]);
                closestCalls++;  // Count calls to closest_sq
                if (closest != a[i]) {
                    d.push_back(abs(closest - a[i]));
                    not_sq++;
                } else {
                    sq++;
                }
            }
        }

        // Insert checks after the primary analysis loop
        check_frequent_calls_invariant(closestCalls, 20000);  // Arbitrary threshold for frequent calls
        check_zero_candies_invariant(zeros, n / 2);  // Threshold based on half of input size
        check_imbalance_invariant(sq, not_sq, n / 4);  // Arbitrary threshold for imbalance

        int half = n / 2;
        if (sq + zeros == half) {
            cout << 0 << endl;
        } else if (sq + zeros > half) {
            if (zeros <= half) {
                cout << (sq + zeros - half) << endl;
            } else {
                cout << sq + 2 * (zeros - half) << endl;
            }
        } else {
            int cnt = not_sq - half;
            sort(d.begin(), d.end());
            long long ans = 0;
            for (int i = 0; i < cnt; ++i) {
                ans += d[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}