#include <bits/stdc++.h>
using namespace std;

// Checker function for input size
void check_input_size_invariant(int n) {
    if (n >= 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to large input size!" << endl;
        abort();
    }
}

// Checker function for algorithm complexity
void check_algorithm_complexity_invariant(int operations, int threshold) {
    if (operations > threshold) {
        cerr << "Warning: Performance bottleneck due to high complexity in Floyd-Warshall execution!" << endl;
        abort();
    }
}

int myfor(int i, int n, function<void(int)> f) {
    return (i < n ? (f(i), myfor(i + 1, n, f)) : 0);