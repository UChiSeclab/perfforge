#include <bits/stdc++.h>
using namespace std;

// Function to check large vector size condition
void check_large_vectors_condition(int n, int m, const vector<int>& v1, const vector<int>& v2) {
    if (n + m > 1500000) {
        cerr << "Warning: Performance bottleneck triggered due to large vector sizes for binary search!" << endl;
        abort();
    }
}

// Function to check high iteration count condition
void check_high_iteration_condition(int n, int m) {
    if (n > 500000 && m > 500000) {
        cerr << "Warning: High iteration count due to large values of n and m!" << endl;
        abort();
    }
}

// Function to check dynamic growth condition
void check_dynamic_growth_condition(const vector<int>& v1, const vector<int>& v2) {
    if (v1.size() > 1000000 || v2.size() > 1000000) {
        cerr << "Warning: Performance bottleneck due to excessive dynamic growth of vectors!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    vector<int> v1, v2;
    cin >> n >> m;

    // Place check after reading inputs
    check_large_vectors_condition(n, m, v1, v2);
    check_high_iteration_condition(n, m);

    if (n == 0) {
        cout << m * 3;
        return 0;
    }
    if (m == 0) {
        cout << n * 2;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        v1.push_back(i * 2);
    }
    for (int i = 1; i <= m; i++) {
        v2.push_back(i * 3);
    }

    // Check dynamic growth after population of vectors
    check_dynamic_growth_condition(v1, v2);

    for (int i = 6; i <= min(v1[v1.size() - 1], v2[v2.size() - 1]); i += 6) {
        if (binary_search(v1.begin(), v1.end(), i) &&
            binary_search(v2.begin(), v2.end(), i)) {
            if (v1[v1.size() - 1] <= v2[v2.size() - 1]) {
                v1.push_back(v1[v1.size() - 1] + 2);
            } else {
                v2.push_back(v2[v2.size() - 1] + 3);
            }
        }
    }
    cout << max(v1[v1.size() - 1], v2[v2.size() - 1]);
    return 0;
}