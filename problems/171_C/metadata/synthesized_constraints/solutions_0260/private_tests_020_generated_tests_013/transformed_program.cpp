#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_iteration_invariant(int carrots) {
    if (carrots > 90) { // Considering the upper edge of the constraint
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count!" << endl;
        abort();
    }
}

void check_frequent_stack_ops_invariant(int operation_count) {
    if (operation_count > 900) { // Arbitrary threshold related to stack operations
        cerr << "Warning: Performance bottleneck condition triggered - frequent stack operations!" << endl;
        abort();
    }
}

void check_complex_arithmetic_invariant(int arithmetic_count) {
    if (arithmetic_count > 900) { // Arbitrary threshold for arithmetic operations
        cerr << "Warning: Performance bottleneck condition triggered - complex arithmetic operations!" << endl;
        abort();
    }
}

int main() {
    int carrots = 2;
    int calories = 0;
    int chocolate_spread = 100;
    int pack_of_flour = 1;
    int egg = 1;
    stack<int> mixing_bowl;
    mixing_bowl.push(calories);

    cin >> carrots;
    
    // Check for high iteration count at the start
    check_high_iteration_invariant(carrots);
    
    // Initialize counters for operations
    int operation_count = 0;
    int arithmetic_count = 0;

    for (int i = 1; i <= carrots; ++i) {
        cin >> chocolate_spread;
        mixing_bowl.push(chocolate_spread);
        mixing_bowl.top() *= pack_of_flour;
        chocolate_spread = mixing_bowl.top();
        mixing_bowl.pop();
        mixing_bowl.top() += chocolate_spread;
        mixing_bowl.push(pack_of_flour);
        mixing_bowl.top() += egg;
        pack_of_flour = mixing_bowl.top();
        mixing_bowl.pop();

        // Increment operation counters
        operation_count += 7; // Each iteration has 7 stack operations
        arithmetic_count += 5; // Each iteration has 5 arithmetic operations

        // Check for frequent stack manipulations and complex arithmetic operations
        check_frequent_stack_ops_invariant(operation_count);
        check_complex_arithmetic_invariant(arithmetic_count);
    }

    while (!mixing_bowl.empty()) {
        cout << mixing_bowl.top() << '\n';
        mixing_bowl.pop();
    }
    
    return 0;
}