#include <bits/stdc++.h>
using namespace std;

string t[31];
int n;

// Checker functions
void check_loop_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations!" << endl;
        abort();
    }
}

void check_substring_check_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive substring checks!" << endl;
        abort();
    }
}

bool fin(string s) {
    for (int i = 0; i < n; ++i)
        if (t[i].find(s) != string::npos) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> t[i];

    // Check for excessive loop iterations
    check_loop_iteration_invariant(n * 26 * 26 * 26 > 10000); // Example threshold for loop iteration check

    for (int l = 1; l <= 3; ++l)
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    string s = "";
                    s += ('a' + i);
                    if (l > 1) s += ('a' + j);
                    if (l > 2) s += ('a' + k);
                    
                    // Check for frequent substring checks
                    check_substring_check_invariant(n > 20 && l == 3); // Example threshold for substring check

                    if (fin(s)) {
                        cout << s;
                        exit(0);
                    }
                }
            }
        }
    return 0;
}