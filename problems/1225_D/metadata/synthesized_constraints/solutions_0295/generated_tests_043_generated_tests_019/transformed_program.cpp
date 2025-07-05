#include <bits/stdc++.h>
using namespace std;

long long cnt[200000];
long long sosuu[200000];

// Checker functions
void check_high_factor_count(int factorCount, int threshold) {
    if (factorCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high factor count!" << endl;
        abort();
    }
}

void check_nested_loop_depth(int depth, int threshold) {
    if (depth > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to deep nested loop!" << endl;
        abort();
    }
}

void check_non_trivial_factorization(int operations, int threshold) {
    if (operations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to non-trivial factorization!" << endl;
        abort();
    }
}

int main() {
    sosuu[1] = 1;
    for (long long i = 2; i <= 100000; ++i) {
        if (sosuu[i] == 1) continue;
        for (long long q = 2; i * q <= 100000; ++q) {
            sosuu[i * q] = 1;
        }
    }
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
        long long a = 0;
        cin >> a;
        int factorCount = 0; // Track number of factors
        for (long long i = 2; i <= 100000; ++i) {
            if (sosuu[i] == 1) continue;
            long long hoge = 1;
            for (long long q = 0; q < k; ++q) {
                hoge *= i;
                if (hoge > a) break;
            }
            if (hoge > a) break;
            while (a % hoge == 0) {
                a /= hoge;
                factorCount++;
            }
        }
        // Check factor count threshold
        check_high_factor_count(factorCount, 10); // Assume 10 is a meaningful threshold
        cnt[a]++;
    }
    
    for (long long i = 1; i <= 100000; ++i) {
        long long target = 1;
        long long now = i;
        int nestedLoopDepth = 0; // Track depth of nested operations
        for (long long q = 2; q <= sqrt(now); ++q) {
            if (sosuu[q] == 1) continue;
            long long cnt = 0;
            while (now % q == 0) {
                now /= q;
                cnt++;
            }
            if (cnt != 0) {
                if (cnt >= k) {
                    target = 200000;
                    break;
                }
                cnt = k - cnt;
                for (long long t = 0; t < cnt; ++t) {
                    if (target > 100000) break;
                    target *= q;
                    nestedLoopDepth++;
                }
                if (target > 100000) break;
            }
        }
        
        // Check nested loop depth threshold
        check_nested_loop_depth(nestedLoopDepth, 10); // Assume 10 as a threshold
        if (now != 1) {
            int nonTrivialFactorizationOps = 0; // Track operations for non-trivial factorization
            for (long long t = 0; t < k - 1; ++t) {
                if (target > 100000) break;
                target *= now;
                nonTrivialFactorizationOps++;
            }
            // Check non-trivial factorization threshold
            check_non_trivial_factorization(nonTrivialFactorizationOps, 5); // Assume 5 as a threshold
        }
        
        if (target <= 100000) {
            if (target == i) {
                ans += cnt[i] * (cnt[i] - 1LL);
            } else {
                ans += cnt[i] * cnt[target];
            }
        }
    }
    cout << ans / 2LL << endl;
}