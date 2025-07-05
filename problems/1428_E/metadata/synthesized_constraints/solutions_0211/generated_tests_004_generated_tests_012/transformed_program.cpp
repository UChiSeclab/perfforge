#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], k;

long long cost(int len, int parts) {
    int len1 = len / parts;
    int len2 = len1 + 1;
    int cnt2 = len % parts, cnt1 = parts - cnt2;
    return (1LL * cnt1 * len1 * len1 + 1LL * cnt2 * len2 * len2);
}

struct node {
    int len, parts;
    node() { len = parts = 0; }
    node(int _len, int _parts) {
        len = _len;
        parts = _parts;
    }
    long long optimizerAnswer() const {
        return cost(len, parts) - cost(len, parts + 1);
    }
};

bool operator<(node a, node b) {
    return a.optimizerAnswer() < b.optimizerAnswer();
}

// Checker for high number of partitions compared to carrots
void check_high_partition_invariant(int n, int k) {
    if (k > 10 * n) { // Arbitrary threshold: if k is significantly larger than n
        cerr << "Warning: High number of carrot partitions compared to carrots!" << endl;
        abort();
    }
}

// Checker for large variability in carrot sizes
void check_variability_invariant(const vector<int>& a) {
    int max_length = *max_element(a.begin(), a.end());
    int min_length = *min_element(a.begin(), a.end());
    if (max_length > 10 * min_length) { // Arbitrary threshold: high variability
        cerr << "Warning: Large variability in carrot sizes!" << endl;
        abort();
    }
}

// Checker for excessive cost function calls
void check_cost_function_invariant(int num_calls) {
    if (num_calls > 1000000) { // Arbitrary threshold for excessive calls
        cerr << "Warning: Cost function called excessively!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    
    vector<int> carrot_lengths(n);
    priority_queue<node> pq;
    
    for (int(i) = (1); (i) <= (n); ++(i)) {
        cin >> a[i];
        carrot_lengths[i-1] = a[i];
        pq.push(node(a[i], 1));
    }

    // Check for high number of partitions
    check_high_partition_invariant(n, k);
    // Check for large variability in carrot sizes
    check_variability_invariant(carrot_lengths);
    
    int cost_function_calls = 0; // Track number of cost function calls

    while (k-- > n) {
        node u = pq.top();
        pq.pop();
        pq.push(node(u.len, u.parts + 1));
        
        // Increment cost function call count for each optimizerAnswer computation
        cost_function_calls++;
        check_cost_function_invariant(cost_function_calls); // Check excessive calls
    }
    
    long long ans = 0;
    while (pq.size()) {
        node u = pq.top();
        pq.pop();
        ans += cost(u.len, u.parts);
        
        // Increment cost function call count for each final cost computation
        cost_function_calls++;
    }

    cout << ans;
}