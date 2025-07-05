#include <bits/stdc++.h>
using namespace std;

// Function implementing the initial state invariant check
void check_initial_state_invariant(int x, int y) {
    if (x > 2 * y) {
        cerr << "Warning: Performance bottleneck condition triggered - x is much larger than y!" << endl;
        abort();
    }
}

// Function implementing the iteration dynamics invariant check
void check_iteration_dynamics_invariant(int a, int b, int x, int y) {
    if (b < y && a < x && a > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - slow iteration dynamics!" << endl;
        abort();
    }
}

// Function implementing the machine application invariant check
void check_machine_application_invariant(int a, int b, int x, int y) {
    if (a < x && b >= y) {
        cerr << "Warning: Performance bottleneck condition triggered - unbalanced machine application!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    
    // Place the initial state check after reading the input
    check_initial_state_invariant(x, y);
    
    int a = 0, b = 1;
    if (y == 0) {
        cout << "No";
        return 0;
    }
    while (1) {
        // Place the iteration dynamics check before applying loop logic
        check_iteration_dynamics_invariant(a, b, x, y);
        
        if (b < y) {
            a++;
            b++;
        } else if (a < x && a > 0) {
            a += 2;
        } else {
            break;
        }
        
        // Place the machine application check after loop processes
        check_machine_application_invariant(a, b, x, y);
    }
    if (a == x && y == b)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}