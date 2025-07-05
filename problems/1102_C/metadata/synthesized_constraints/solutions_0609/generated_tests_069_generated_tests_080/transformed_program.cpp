#include <bits/stdc++.h>
using namespace std;

// Define checkers
void check_sort_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting with minimal changes!" << endl;
        abort();
    }
}

void check_vector_modification_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent modifications on vector!" << endl;
        abort();
    }
}

void check_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration with ineffective progress!" << endl;
        abort();
    }
}

void check_input_invariant(int n, int x, int y) {
    if (n == 100 && x <= y) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum doors with insufficient break power!" << endl;
        abort();
    }
}

// Main program
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    
    // Check input invariant
    check_input_invariant(n, x, y);
    
    vector<int> v;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }
    
    if (x > y) {
        cout << n;
        return 0;
    } else {
        sort(v.begin(), v.end());

        // Check sort invariant initially
        check_sort_invariant(v.size() > 1 && x <= y);

        for (int i = 0; i < v.size(); i++) {
            v[0] -= x;

            if (v[0] <= 0) {
                count++;
                v.erase(v.begin() + 0);

                // Check vector modification invariant
                check_vector_modification_invariant(true);
            }

            v[0] = v[0] + y;
            sort(v.begin(), v.end());

            // Check sort invariant after each modification
            check_sort_invariant(v.size() > 1 && x <= y);

            if (v[0] > x) {
                
                // Check iteration invariant
                check_iteration_invariant(i > 100 && x <= y);
                
                cout << count << endl;
                return 0;
            }
        }
        cout << count;
        return 0;
    }
}