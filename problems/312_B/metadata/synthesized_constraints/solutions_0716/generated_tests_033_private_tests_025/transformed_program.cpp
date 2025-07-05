#include <bits/stdc++.h>
using namespace std;

// Checker for probability values
void check_probability_invariant(double p1, double p2) {
    if (p1 < 0.1 && p2 < 0.1) {  // Example threshold for "significantly less than 1"
        cerr << "Warning: Performance bottleneck condition triggered - low probability values!" << endl;
        abort();
    }
}

// Checker for excessive loop iterations
void check_loop_invariant(int iteration_count) {
    if (iteration_count > 1000) {  // Example threshold for large number of iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations!" << endl;
        abort();
    }
}

// Checker for excessive recursive terms
void check_recursive_calculation_invariant(int j) {
    if (j > 1000) {  // Example threshold for large number of recursive terms
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive terms!" << endl;
        abort();
    }
}

double a, b, c, d, p1, np1, p2, np2, ans;
double prob_n(int n) { return powl(np1, n - 1) * powl(np2, n - 1) * p1; }

int main() {
    cin >> a >> b >> c >> d;
    p1 = a / b;
    p2 = c / d;

    // Check probabilities after calculation
    check_probability_invariant(p1, p2);

    np1 = 1.0 - p1;
    np2 = 1.0 - p2;
    
    a = prob_n(1);
    b = prob_n(2);
    ans += a + b;
    
    int j = 3;
    int iteration_count = 0;
    
    while (abs(a - b) > 0.0000000000001) {
        // Check loop iteration count
        check_loop_invariant(++iteration_count);
        // Check recursive calculation
        check_recursive_calculation_invariant(j);

        a = prob_n(j);
        ans += a;
        j++;
        swap(a, b);
    }
    
    cout << fixed << setprecision(12) << ans;
    return 0;
}