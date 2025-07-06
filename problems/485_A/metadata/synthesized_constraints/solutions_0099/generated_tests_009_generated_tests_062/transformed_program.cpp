#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

void check_high_iteration_count(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - loop reached maximum iterations!" << endl;
        abort();
    }
}

void check_large_modulo_value(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large modulo value relative to a!" << endl;
        abort();
    }
}

void check_non_divisible_sequence(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - non-divisible sequence!" << endl;
        abort();
    }
}

int main() {
    int a, m;
    cin >> a >> m;

    // Check for large modulo value relative to a
    check_large_modulo_value(m > a && m > 50000);  // Example condition

    a %= m;
    bool can = false;
    int iteration_count = 0;
    const int MAX_ITERATIONS = 10000000;
    
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        a *= 2;
        if (a >= m) a -= m;
        if (a == 0) {
            can = true;
            break;
        }
        iteration_count++;
    }

    // Check if the loop reached maximum iterations
    check_high_iteration_count(iteration_count >= MAX_ITERATIONS);

    // Check for non-divisible sequence
    check_non_divisible_sequence(!can && iteration_count >= (MAX_ITERATIONS - 1));

    if (can)
        cout << "Yes";
    else
        cout << "No";
    cout << '\n';
    return 0;
}