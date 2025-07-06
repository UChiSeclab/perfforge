#include <bits/stdc++.h>
using namespace std;

map<int, int> m1, m2;
int a[105], b[105];

// Checker for state space explosion
void check_state_space_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: State space invariant triggered - large number of unique states!" << endl;
        abort();
    }
}

// Checker for combinatorial explosion
void check_combinatorial_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Combinatorial invariant triggered - excessive valid state combinations!" << endl;
        abort();
    }
}

// Checker for input structure impact
void check_input_structure_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Input structure invariant triggered - redundant or similar states!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] = a[i] - b[i] * k;
    }
    m2[0] = 0;

    // Check if b[i] values form a large range, potentially leading to state space explosion
    set<int> b_values(b + 1, b + n + 1);
    check_state_space_invariant(b_values.size() > 50);  // Threshold can be adjusted

    for (int i = 1; i <= n; ++i) {
        m1.clear();
        m1 = m2;
        
        // Check for combinatorial explosion due to a large m1 size
        check_combinatorial_invariant(m1.size() > 1000);  // Arbitrary threshold
        
        for (auto j : m1) {
            m2[j.first + b[i]] = max(m2[j.first + b[i]], m1[j.first] + a[i]);
        }
    }

    // Check if m2 has too many similar states, indicating input structure issues
    check_input_structure_invariant(m2.size() > 10000);  // Another arbitrary threshold

    if (m2[0]) {
        cout << m2[0];
    } else {
        cout << -1;
    }
}