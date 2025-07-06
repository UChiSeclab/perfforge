#include <bits/stdc++.h>
using namespace std;

void check_multiset_operations_invariant(size_t multisetSize, long long n) {
    if (multisetSize > n / 2) {
        cerr << "Warning: Performance bottleneck due to large multiset operations!" << endl;
        abort();
    }
}

void check_stage_invariant(long long currentStage, long long requiredStage, long long n) {
    if ((currentStage - requiredStage) > log2(n) / 2) {
        cerr << "Warning: Performance bottleneck due to large stage difference!" << endl;
        abort();
    }
}

void check_loop_complexity_invariant(long long n, long long iterationCount) {
    if (iterationCount > n * log2(n)) {
        cerr << "Warning: Performance bottleneck due to high iteration count in nested loops!" << endl;
        abort();
    }
}

signed main() {
    long long n;
    cin >> n;
    long long k[n];
    long long curst = 1, curval = -1;
    for (long long i = 0; i < n; i++) {
        if (curst == i + 1) {
            curval++;
            curst *= 2;
        }
        k[i] = curval;
    }
    cerr << "k : \n";
    for (long long i = 0; i < n; i++) {
        cerr << k[i] << ' ';
    }
    cerr << endl;
    long long a[n];
    long long num;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) num = i;
    }
    multiset<long long> s;
    long long it = n - 1;
    long long ans = 0;
    long long iterationCount = 0; // Track iteration count for loop complexity invariant
    for (long long i = curval; i > k[num]; i--) {
        while (k[it] == i) {
            s.insert(a[it]);
            it--;
            iterationCount++;
        }
        check_multiset_operations_invariant(s.size(), n); // Check multiset operations invariant
        ans += *(s.begin());
        s.erase(s.begin());
    }
    check_stage_invariant(curval, k[num], n); // Check stage invariant
    check_loop_complexity_invariant(n, iterationCount); // Check loop complexity invariant
    
    cout << ans;
    return 0;
}