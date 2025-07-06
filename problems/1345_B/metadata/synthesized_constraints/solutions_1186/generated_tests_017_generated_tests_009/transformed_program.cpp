#include <bits/stdc++.h>
using namespace std;
const long long Max = 1000000000;

// Checkers for performance invariants
void check_vector_precomputation(bool condition) {
    if (condition) {
        cerr << "Warning: Vector precomputation redundancy detected!" << endl;
        abort();
    }
}

void check_iteration_efficiency(int n, int iter_count) {
    if (iter_count > n) { // Assuming iterating more than n times is inefficient
        cerr << "Warning: Inefficient iteration over vector detected!" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    
    // Precompute the vector `v` once
    vector<long long> v;
    long long x = 5;
    v.push_back(2);
    for (long long i = 1; i <= 25820; i++) {
        long long k = v[v.size() - 1] + x;
        v.push_back(k);
        x += 3;
    }
    
    // Check for redundant precomputation of vector
    check_vector_precomputation(v.size() > 0); // Should only be precomputed once
    
    while (t--) {
        long long n;
        cin >> n;
        int cnt = 0;
        
        // Start counting the number of pyramids
        int iter_count = 0; // Count number of iterations for efficiency check
        for (int i = v.size() - 1; i >= 0; i--) {
            cnt += (n / v[i]);
            n = (n - (n / v[i] * v[i]));
            iter_count++;
        }
        
        // Check for inefficient iterations over vector
        check_iteration_efficiency(n, iter_count);
        
        cout << cnt << endl;
    }
}