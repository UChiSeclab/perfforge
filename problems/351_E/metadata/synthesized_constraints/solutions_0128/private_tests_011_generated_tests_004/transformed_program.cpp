#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], n;
map<int, vector<int>> m;
vector<pair<int, vector<int>>> v;
int bit[2 * N] = {0};

void ud(int i, int v) {
    for (i += N; i < 2 * N; i += i & -i) bit[i] += v;
}

int qr(int i) {
    int ans = 0;
    for (i += N; i; i ^= i & -i) ans += bit[i];
    return ans;
}

long long calc(int& opCount) {
    long long inv = 0;
    for (int i = n - 1; i >= 0; --i) {
        inv += qr(a[i] - 1);
        ud(a[i], 1);
        opCount++;  // Counting BIT operations
    }
    for (int i = 0; i < n; ++i) {
        ud(a[i], -1);
    }
    return inv;
}

void pa() {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ",";
        cout << a[i];
    }
    cout << "]\n";
}

void check_bit_operation_invariant(int operations, int threshold) {
    if (operations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive BIT operations!" << endl;
        abort();
    }
}

void check_nested_iteration_invariant(int vectorSize, int threshold) {
    if (vectorSize > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested iterations!" << endl;
        abort();
    }
}

void check_repeated_inversion_invariant(int inversionCalculations, int threshold) {
    if (inversionCalculations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated inversion calculations!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        a[i] = abs(a[i]);
        m[a[i]].push_back(i);
    }
    
    // Check for potential nested iteration bottleneck
    check_nested_iteration_invariant(m.size(), 100);  // Assuming a threshold of 100 based on n

    // Calculate initial inversions
    int opCount = 0;
    long long bv = calc(opCount);
    
    // Check for excessive BIT operations
    check_bit_operation_invariant(opCount, 5000);  // Arbitrary threshold for demonstration

    for (int i = v.size() - 1; i >= 0; --i) {
        vector<int>& w = v[i].second;
        int bst = 0;
        int inversionCount = 0;
        for (int j = 0; j < w.size(); ++j) {
            a[w[j]] = -a[w[j]];
            inversionCount++;
            long long inv = calc(opCount);
            if (inv < bv) {
                bv = inv;
                bst = j + 1;
            }
        }
        
        // Check for repeated inversion calculations
        check_repeated_inversion_invariant(inversionCount, 50);  // Arbitrary threshold for demonstration

        for (int j = 0; j < w.size(); ++j) {
            if (j >= bst) a[w[j]] = -a[w[j]];
        }
    }
    cout << bv << "\n";
    return 0;
}