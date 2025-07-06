#include <bits/stdc++.h>
using namespace std;

const int M = 100, N = 1000;
int k[3], kmax, lit[N + 1];

// Recursive depth check
void check_recursion_invariant(int depth, int maxDepth) {
    if (depth > maxDepth) {
        cerr << "Warning: Recursion depth invariant triggered - excessive recursion depth" << endl;
        abort();
    }
}

// Nested loop iteration check
void check_loop_invariant(int iterations, int threshold) {
    if (iterations > threshold) {
        cerr << "Warning: Loop invariant triggered - excessive iterations in nested loops" << endl;
        abort();
    }
}

bool check(int n = 0, int xmax = 0, int depth = 0) {
    check_recursion_invariant(depth, 100); // Check for excessive recursion depth
    
    if (n == 3) {
        for (int y = xmax; y <= N; y++)
            if (!lit[y]) return false;
        return true;
    }

    int p = n + 1, q = k[n];
    int loopIterations = 0;
    
    for (int x = 0; x <= M; x++) {
        check_loop_invariant(++loopIterations, 1000); // Check for excessive loop iterations
        
        for (int y = x; y <= N; y += q) lit[y]++;
        if (check(p, max(x, xmax), depth + 1)) return true;
        for (int y = x; y <= N; y += q) lit[y]--;
    }
    return false;
}

int main() {
    for (int i = 0; i < 3; i++) cin >> k[i];
    sort(k, k + 3), kmax = k[2];
    
    if (check())
        cout << "YES";
    else
        cout << "NO";
}