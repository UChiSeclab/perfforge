#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_vector_operations_invariant(int n, int numOperations) {
    if (numOperations > n * 10) {
        cerr << "Warning: Performance bottleneck due to excessive vector operations!" << endl;
        abort();
    }
}

void check_loop_iteration_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck due to high loop iteration count!" << endl;
        abort();
    }
}

void check_decision_complexity_invariant(int numDecisions) {
    if (numDecisions > 1000) {
        cerr << "Warning: Performance bottleneck due to complex decision making in loops!" << endl;
        abort();
    }
}

void check_redundant_computation_invariant(int redundantComputations) {
    if (redundantComputations > 1000) {
        cerr << "Warning: Performance bottleneck due to redundant computations!" << endl;
        abort();
    }
}

void check_memory_usage_invariant(size_t memoryUsed) {
    if (memoryUsed > 50000000) {
        cerr << "Warning: Performance bottleneck due to inefficient memory usage!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    
    check_loop_iteration_invariant(n); // Check for excessive loop iterations
    
    long long mi = min(r1, min(r2, r3));
    long long sum = d * (n - 1);
    long long a[n];
    pair<long long, long long> b[n];
    pair<long long, long long> b1[n];
    
    int operationCount = 0; // Track vector operations
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        vector<long long> v;
        vector<long long> v1;
        
        // Counting vector operations
        v1.push_back(r2 + mi);
        operationCount++;
        
        v1.push_back(r1 * a[i] + r1 + mi);
        operationCount++;
        
        v.push_back(r1 * a[i] + r3);
        operationCount++;
        
        v1.push_back(r1 * a[i] + r3);
        operationCount++;
        
        v1.push_back(r1 * a[i] + r2 + mi);
        operationCount++;
        
        v.push_back(r3 * a[i] + r3);
        operationCount++;
        
        v1.push_back(r3 * a[i] + r3);
        operationCount++;
        
        v1.push_back(r3 * a[i] + r2 + mi);
        operationCount++;
        
        v1.push_back(r3 * a[i] + r1 + mi);
        operationCount++;
        
        b[i] = {*min_element(v.begin(), v.end()), *min_element(v1.begin(), v1.end())};
        b1[i] = b[i];
        b[i].first = min(b[i].first, b[i].second + 2 * d);
    }
    
    check_vector_operations_invariant(n, operationCount); // Check for excessive vector operations
    
    long long pr1[n + 1];
    pr1[0] = 0;
    pr1[1] = b[0].first;
    
    int decisionCount = 0; // Track decision complexity
    for (long long i = 2; i <= n; ++i) {
        pr1[i] = 1e18;
        pr1[i] = min(pr1[i], pr1[i - 1] + b[i - 1].first);
        
        pr1[i] = min(pr1[i], pr1[i - 2] + b[i - 2].second + 2 * d + b[i - 1].second);
        if (i >= 3) {
            pr1[i] = min(pr1[i], pr1[i - 3] + b[i - 3].second + 4 * d + b[i - 2].second + b[i - 1].second);
            decisionCount++;
        }
        
        if (i == n) {
            pr1[i] = min(pr1[i], pr1[i - 2] + b[i - 2].second + d + b[i - 1].first);
            decisionCount++;
        }
    }
    
    check_decision_complexity_invariant(decisionCount); // Check for complex decision making
    
    cout << pr1[n] + sum;
    return 0;
}