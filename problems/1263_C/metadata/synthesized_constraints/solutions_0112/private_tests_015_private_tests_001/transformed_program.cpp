#include <bits/stdc++.h>
using namespace std;

// Function to check the sqrt loop invariant
void check_sqrt_loop_invariant(int n) {
    if (n > 1000000) {  // Arbitrary large threshold for demonstration
        cerr << "Warning: sqrt_loop_invariant triggered - too many iterations due to large n" << endl;
        abort();
    }
}

// Function to check the set insertion invariant
void check_set_insertion_invariant(int n) {
    if (n > 1000000) {  // Arbitrary large threshold for demonstration
        cerr << "Warning: set_insertion_invariant triggered - excessive unique elements in set" << endl;
        abort();
    }
}

// Function to check the output size invariant
void check_output_size_invariant(int size) {
    if (size > 10000) {  // Arbitrary threshold for demonstration
        cerr << "Warning: output_size_invariant triggered - excessive output size" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        
        // Checking invariants after input
        check_sqrt_loop_invariant(n);
        check_set_insertion_invariant(n);
        
        if (n == 1) {
            cout << 2 << endl;
            cout << 0 << " " << 1 << endl;
            continue;
        }
        set<int> s;
        set<int>::iterator it;
        for (i = 1; i <= sqrt(n) + 1; i++) {
            if (s.find(n / i) == s.end()) {
                s.insert(i);
                if (i != n / i) s.insert(n / i);
            }
        }
        s.insert(0);

        // Checking output size before printing
        check_output_size_invariant(s.size());

        cout << s.size() << endl;
        for (it = s.begin(); it != s.end(); it++) cout << *it << " ";
        cout << endl;
    }
    return 0;
}