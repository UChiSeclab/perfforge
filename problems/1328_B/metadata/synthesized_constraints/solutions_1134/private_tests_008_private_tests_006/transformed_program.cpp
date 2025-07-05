#include <bits/stdc++.h>
using namespace std;

// Checker function to detect large k value
void check_k_invariant(int n, int k) {
    if (k > (n * (n - 1)) / 2 - n) {
        cerr << "Warning: k_invariant triggered - high k value causing excessive loop iterations" << endl;
        abort();
    }
}

// Checker function for iteration depth
void check_iteration_depth_invariant(int n, int k) {
    if (k > (n * (n - 1)) / 2 - n) {
        cerr << "Warning: iteration_depth_invariant triggered - excessive loop iterations due to large k" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        // Check for performance bottleneck before entering the loop
        check_k_invariant(n, k);
        check_iteration_depth_invariant(n, k);

        string s(n, 'a');
        for (int i = n - 2; i >= 0; i--) {
            if (k <= (n - i - 1)) {
                s[i] = 'b';
                s[n - k] = 'b';
                cout << s << endl;
                break;
            }
            k -= (n - i - 1);
        }
    }
}