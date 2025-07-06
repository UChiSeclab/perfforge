#include <bits/stdc++.h>
using namespace std;

int n, m;
int min_len = 1000000;
int reached[30000];

void check_small_initial_large_target(int n, int m) {
    if (n < m / 2) { 
        cerr << "Warning: Performance bottleneck condition triggered - small initial value leading to deep recursive exploration!" << endl;
        abort();
    }
}

void check_high_recursion_depth(int depth) {
    if (depth > 10000) { // Arbitrary threshold based on maximum recursion depth observed
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth!" << endl;
        abort();
    }
}

void check_overshooting(int k, int m) {
    if (k > 2 * m) { // Condition that indicates overshooting m significantly
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion due to overshooting!" << endl;
        abort();
    }
}

void addElement(int k, int m, int depth) {
    check_high_recursion_depth(depth); // Check for high recursion depth
    check_overshooting(k, m); // Check for overshooting condition
    
    if (reached[k] != 0 && reached[k] <= depth) {
        return;
    }
    reached[k] = depth;
    if (k <= m) {
        addElement(k * 2, m, depth + 1);
    }
    if (k - 1 > 0) {
        addElement(k - 1, m, depth + 1);
    }
}

int main() {
    for (int i = 0; i < 30000; i++) {
        reached[i] = 0;
    }
    cin >> n >> m;
    
    // Check for small initial value leading to deep recursion
    check_small_initial_large_target(n, m);
    
    addElement(n, m, 1);
    cout << reached[m] - 1;
    return 0;
}