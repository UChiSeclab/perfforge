#include <bits/stdc++.h>
using namespace std;

char s[220], t[220], r[220];

// Function to check for large `s` size
void check_large_s_size(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large string 's'!" << endl;
        abort();
    }
}

// Function to check for excessive substring checks
void check_excessive_substring_checks(bool condition) {
    if (condition) {
        cerr << "Warning: Excessive substring checks due to large input size!" << endl;
        abort();
    }
}

// Function to check for redundant operations
void check_redundant_operations(bool condition) {
    if (condition) {
        cerr << "Warning: Redundant operations detected due to nested loops!" << endl;
        abort();
    }
}

int main(void) {
    int n, m, l;
    int i, j, k;
    int p;
    int o;
    
    scanf("%s", s);
    scanf("%s", t);
    
    n = strlen(s);
    m = strlen(t);

    // Check performance bottlenecks
    check_large_s_size(n > 150); // Approximate threshold based on constraints
    check_excessive_substring_checks(n * n > 30000); // Quadratic threshold for nested loops
    check_redundant_operations(n > 190 && m < 10); // Specific case where redundant operations are likely

    for (i = o = 0; i < n; i++)
        for (j = i; j < n; j++) {
            for (k = l = 0; k < n; k++)
                if (k < i || j < k) r[l++] = s[k];
            for (k = p = 0; k < l && p < m; k++)
                if (r[k] == t[p]) ++p;
            if (p == m) o = max(o, j - i + 1);
        }
    
    printf("%d\n", o);
    return 0;
}