#include <bits/stdc++.h>
using namespace std;

// Checker for inefficient calculation of max_element
void check_max_element_invariant(int loopCount, int arraySize) {
    if (loopCount > 50 && arraySize > 50) {
        cerr << "Warning: max_element invariant triggered - repeated maximum calculation in loop" << endl;
        abort();
    }
}

// Checker for nested loop complexity
void check_nested_loop_invariant(int outerLoopSize, int innerLoopSize) {
    if (outerLoopSize > 50 && innerLoopSize > 50) {
        cerr << "Warning: nested loop invariant triggered - potential quadratic complexity" << endl;
        abort();
    }
}

// Checker for high input size impacting performance
void check_input_size_invariant(int inputSize, int threshold) {
    if (inputSize > threshold) {
        cerr << "Warning: input size invariant triggered - large input impacting performance" << endl;
        abort();
    }
}

int main() {
    int cnt = 0;
    int t, c;
    cin >> t;

    // Check input size invariant
    check_input_size_invariant(t, 75); // Adjust threshold as appropriate within constraints

    vector<int> r;
    for (int i = 0; i < t; i++) {
        cin >> c;
        r.push_back(c);
    }

    // Check nested loop complexity
    check_nested_loop_invariant(t, r.size()); // Checks for potential quadratic behavior

    for (int j = 0; j < t; j++) {
        // Check max_element calculation inefficiency
        check_max_element_invariant(t, r.size());
        
        cnt += abs((*max_element(r.begin(), r.end()) - r[j]));
    }

    cout << cnt << endl;
}