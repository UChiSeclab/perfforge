#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_priority_queue_operations(int numOperations, int threshold) {
    if (numOperations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive priority queue operations!" << endl;
        abort();
    }
}

void check_dense_tower_configurations(const vector<int>& heights, int threshold) {
    int fluctuations = 0;
    for (size_t i = 1; i < heights.size(); ++i) {
        if (heights[i] != heights[i-1]) {
            ++fluctuations;
        }
    }
    if (fluctuations > threshold) {
        cerr << "Warning: Performance bottleneck due to dense tower configurations with frequent height variations!" << endl;
        abort();
    }
}

void check_large_sequential_blocks(const vector<int>& heights, int threshold) {
    int sequenceLength = 1;
    for (size_t i = 1; i < heights.size(); ++i) {
        if (heights[i] == heights[i-1]) {
            ++sequenceLength;
        } else {
            if (sequenceLength > threshold) {
                cerr << "Warning: Performance bottleneck due to large sequential block of similar heights!" << endl;
                abort();
            }
            sequenceLength = 1;
        }
    }
    if (sequenceLength > threshold) {
        cerr << "Warning: Performance bottleneck due to large sequential block of similar heights at the end!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    // Insert checks for performance bottlenecks
    check_dense_tower_configurations(heights, 50); // Arbitrary threshold for frequent variations
    check_large_sequential_blocks(heights, 50); // Arbitrary threshold for large sequences

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> ans(n, 1000000000);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(make_pair(heights[i] * -1, i));
    }
    pq.push(make_pair(-1, 0));
    pq.push(make_pair(-1, n - 1));

    int operationCount = 0; // Count priority queue operations
    while (!pq.empty()) {
        int node = pq.top().second;
        int value = pq.top().first * -1;
        pq.pop();
        operationCount++;
        if (ans[node] <= value) continue;
        ans[node] = value;
        if (node + 1 < n) pq.push(make_pair((value + 1) * -1, node + 1));
        if (node - 1 > -1) pq.push(make_pair((value + 1) * -1, node - 1));
    }
    check_priority_queue_operations(operationCount, 300); // Arbitrary threshold for excessive operations

    int as = -1;
    for (int i = 0; i < n; i++) as = max(ans[i], as);
    cout << as << endl;
    return 0;
}