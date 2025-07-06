#include <bits/stdc++.h>
using namespace std;

void smain();
int main() {
    ios_base::sync_with_stdio(0);
    smain();
    return 0;
}

long long n, t;
long long a[1001], d[1001];
long long pd[1001];

// Checker function definitions
void check_iteration_invariant(long long hitCount, long long threshold) {
    if (hitCount > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive iterations triggered!" << endl;
        abort();
    }
}

void check_convergence_invariant(const vector<long long>& p, const vector<long long>& np) {
    if (p == np) {
        cerr << "Warning: Performance bottleneck due to lack of convergence triggered!" << endl;
        abort();
    }
}

void check_nested_iterations_invariant(long long k, long long n, long long threshold) {
    if (k * n > threshold) {
        cerr << "Warning: Performance bottleneck due to extensive nested iterations triggered!" << endl;
        abort();
    }
}

void check_dynamic_array_update_invariant(long long cur, long long prevCur, long long stabilityThreshold) {
    if (abs(cur - prevCur) < stabilityThreshold) {
        cerr << "Warning: Performance bottleneck due to unstable dynamic array updates triggered!" << endl;
        abort();
    }
}

// Main solver function
long long solve() {
    for (long long i = 0; i < n; i++) d[i] = 1;
    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < i; j++)
            if (a[j] <= a[i]) d[i] = max(d[j] + 1, d[i]);
    for (long long i = 0; i < n; i++) pd[i] = d[i];
    
    vector<long long> p(n), np(n);
    long long k = t - 1;
    long long iterationCounter = 0;  // Counter to measure iteration depth
    
    for (; k > 0; --k) {
        for (long long i = 0; i < n; i++) {
            long long cur = 0;
            for (long long j = 0; j < n; j++)
                if (a[j] <= a[i]) cur = max(cur, d[j] + 1);

            np[i] = cur - d[i];
            pd[i] = d[i];
            d[i] = cur;

            // Check for non-reducing dynamic updates
            if (i > 0) {
                check_dynamic_array_update_invariant(cur, pd[i], 1);
            }
        }
        
        iterationCounter += n;
        check_iteration_invariant(iterationCounter, 10000);  // Example threshold

        bool ok = true;
        for (long long i = 0; i < n; i++)
            if (p[i] != np[i]) {
                ok = false;
                break;
            }

        // Check lack of convergence 
        check_convergence_invariant(p, np);

        swap(p, np);
        if (ok) break;
    }
    
    // Check extensive nested iterations
    check_nested_iterations_invariant(k, n, 5000);  // Example threshold

    if (k == 0) return *max_element(d, d + n);

    long long res = 0;
    for (long long i = 0; i < n; i++) res = max(res, pd[i] + p[i] * k);
    
    return res;
}

void smain() {
    for (; cin >> n >> t;) {
        for (long long i = 0; i < n; i++) cin >> a[i];
        cout << solve() << endl;
    }
}