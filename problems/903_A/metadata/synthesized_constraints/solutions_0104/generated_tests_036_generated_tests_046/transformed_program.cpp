#include <bits/stdc++.h>
using namespace std;

void check_test_case_count(int n) {
    if (n > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of test cases!" << endl;
        abort();
    }
}

void check_excessive_loop_iterations(int x) {
    if (x <= 10) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient search space for small x!" << endl;
        abort();
    }
}

void check_inefficient_search_space(int x) {
    if (x < 3 || x == 5) {
        cerr << "Warning: Performance bottleneck condition triggered - small x cannot be formed efficiently!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    
    // Insert check for high number of test cases
    check_test_case_count(n);
    
    while (n--) {
        int x;
        cin >> x;
        
        // Insert checks related to inefficient computation
        check_excessive_loop_iterations(x);
        check_inefficient_search_space(x);
        
        bool b = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                if (3 * i + 7 * j == x) b = 1;
            }
        }
        
        if (b)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}