#include <bits/stdc++.h>
using namespace std;

// Phase 3: Checker Functions
void check_large_iteration_space(int a, int b, int c) {
    int mn = std::min({a, b, c});
    if (mn > 3) {
        cerr << "Warning: Performance bottleneck condition triggered - large iteration space!" << endl;
        abort();
    }
}

void check_redundant_checks(int a, int b, int c) {
    if (a == b || b == c || a == c) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant checks in nested loops!" << endl;
        abort();
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    // Phase 4: Inserting Checker Calls
    check_large_iteration_space(a, b, c); // Check for large iteration space
    check_redundant_checks(a, b, c);      // Check for redundant checks in loops

    int mn = min(min(a, b), c);
    if (mn > 3) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                int cnt = 0;
                for (int t = 0; t <= 27; t++) {
                    if ((t - i) % a == 0 or (t - j) % b == 0 or (t - k) % c == 0) {
                        cnt++;
                    }
                }
                if (cnt == 28) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}