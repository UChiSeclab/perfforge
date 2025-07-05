#include <bits/stdc++.h>
using namespace std;

// Checker for vector size
void check_vector_size_invariant(const vector<long long>& vec) {
    if (vec.size() > 100000) { // Arbitrarily chosen large threshold
        cerr << "Warning: Performance bottleneck - vector 'vec' too large!" << endl;
        abort();
    }
}

// Checker for excessive function calls
void check_function_call_invariant(int callCount) {
    if (callCount > 1000000) { // Arbitrarily chosen large threshold
        cerr << "Warning: Performance bottleneck - 'allok' function called excessively!" << endl;
        abort();
    }
}

// Checker for inefficient nested loop range
void check_nested_loop_invariant(long long mi, long long ma, long long n2) {
    if (ma - mi > n2 / 10) { // Arbitrarily chosen threshold as a fraction of n2
        cerr << "Warning: Performance bottleneck - inefficient nested loop range!" << endl;
        abort();
    }
}

int main() {
    long long(n), (k);
    scanf("%lld%lld", &(n), &(k));
    long long n2 = n;
    vector<long long> vec;

    while (n) {
        vec.push_back(n);
        if (n - 1 > 0) vec.push_back(n - 1);
        n /= 2;
    }

    // Check vector size invariant after the vector is populated
    check_vector_size_invariant(vec);

    long long maxi = 1;
    int functionCallCount = 0; // To count calls to allok

    auto allok = [&](long long v) {
        functionCallCount++;
        long long mi = v, ma = (v % 2) ? v : v + 1;
        long long c = ma - mi + 1;
        while (ma <= n2) {
            mi *= 2;
            ma = 2 * ma + 1;

            // Check nested loop invariant inside the loop
            check_nested_loop_invariant(mi, ma, n2);

            if (mi < n2) c += min(ma, n2) - mi + 1;
        }
        return c >= k;
    };

    for (auto i : vec) {
        while (i <= n2) {
            if (allok(i)) maxi = max(maxi, i);
            i *= 2;
        }
    }

    // Check function call invariant after the loop
    check_function_call_invariant(functionCallCount);

    printf("%lld\n", maxi);
    return 0;
}