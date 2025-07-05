#include <bits/stdc++.h>
using namespace std;

int A[2222][2];

// Function to check for k invariant
void check_k_invariant(int k) {
    if (k > 10000) { // Example threshold for significant slow performance
        cerr << "Warning: k_invariant triggered - excessive repetitions due to high k" << endl;
        abort();
    }
}

// Function to check for range invariant
void check_range_invariant(int min_strength, int max_strength) {
    if (max_strength - min_strength > 1000) {
        cerr << "Warning: range_invariant triggered - wide initial strength range" << endl;
        abort();
    }
}

// Function to check for XOR invariant
void check_xor_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: xor_invariant triggered - frequent strength changes due to XOR" << endl;
        abort();
    }
}

int main() {
    int n, k, x, a, c, s, i;
    bool j;
    scanf("%d%d%d", &n, &k, &x);
    
    // Check k invariant before starting the main computation loop
    check_k_invariant(k);

    vector<int> strengths(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        strengths[i] = a;
        A[a][0]++;
    }
    
    // Determine initial min and max strengths
    int min_strength = *min_element(strengths.begin(), strengths.end());
    int max_strength = *max_element(strengths.begin(), strengths.end());
    
    // Check range invariant based on initial strengths
    check_range_invariant(min_strength, max_strength);

    for (j = 0; k--; j = !j) {
        for (i = s = 0; i <= 2047; i++) {
            c = (s + A[i][j] + 1) / 2 - (s + 1) / 2;
            A[i][!j] += A[i][j] - c;
            A[i ^ x][!j] += c;

            // Example condition to check if XOR is causing too frequent changes
            if (x != 0 && c > 0) { // Placeholder condition, can be refined based on additional analysis
                check_xor_invariant(true);
            }

            s += A[i][j];
            A[i][j] = 0;
        }
    }

    for (i = 2047; i >= 0; i--) {
        if (A[i][j]) {
            printf("%d ", i);
            break;
        }
    }
    for (i = 0; i <= 2047; i++) {
        if (A[i][j]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}