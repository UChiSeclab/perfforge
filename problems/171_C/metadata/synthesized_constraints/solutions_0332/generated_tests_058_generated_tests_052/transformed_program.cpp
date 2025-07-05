#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// Invariant checks implemented as helper functions
void check_loop_invariant(int n) {
    if (n > 90) { // Threshold based on input constraint n <= 100
        cerr << "Warning: Performance bottleneck condition triggered due to high number of iterations!" << endl;
        abort();
    }
}

void check_vector_operations_invariant(size_t vectorSize) {
    if (vectorSize > 50) { // Example threshold for frequent operations
        cerr << "Warning: Performance bottleneck condition triggered due to frequent vector operations!" << endl;
        abort();
    }
}

void check_multiplicative_growth_invariant(int factor) {
    if (factor > 90) { // Threshold based on rapid growth beyond early iterations
        cerr << "Warning: Performance bottleneck condition triggered due to high multiplicative factor!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;

    // Check for loop iterations invariant before processing begins
    check_loop_invariant(n);

    int f = 1;
    vector<int> now = {0};

    while (n--) {
        int a;
        cin >> a;

        now.push_back(a);
        // Check for vector operations invariant
        check_vector_operations_invariant(now.size());

        now.back() *= f;

        // Check for multiplicative growth invariant
        check_multiplicative_growth_invariant(f);

        a = now.back();
        now.pop_back();
        now[0] += a;
        f++;
    }

    cout << now[0] << endl;
}