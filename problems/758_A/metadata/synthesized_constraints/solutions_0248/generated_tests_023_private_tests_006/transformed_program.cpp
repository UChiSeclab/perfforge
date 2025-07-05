#include <bits/stdc++.h>
using namespace std;

// Checker functions

/**
 * Checks if the inefficient sorting condition is met due to the large input size and outliers.
 * @param condition: Boolean condition indicating the presence of a potential inefficiency.
 */
void check_sorting_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient sorting!" << endl;
        abort();
    }
}

/**
 * Checks if the high comparison volume condition is met due to many low values and outliers.
 * @param condition: Boolean condition indicating the presence of excessive comparisons.
 */
void check_comparison_volume_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to high comparison volume!" << endl;
        abort();
    }
}

/**
 * Checks if the selection sort inefficiency condition is met due to large input with sparse high values.
 * @param condition: Boolean condition indicating inefficiency in sorting.
 */
void check_selection_sort_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to selection sort inefficiency!" << endl;
        abort();
    }
}

int main() {
    long long int temp;
    long long int c = 0;
    long long int n;
    long long int *a;
    cin >> n;
    a = (long long int *)malloc(sizeof(long long int) * n);

    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Check for potential performance bottlenecks
    check_sorting_invariant(n > 50); // Inserted check before sorting begins
    check_comparison_volume_invariant(n == 100 && *max_element(a, a + n) > 100000); // Checks for high comparison

    for (long long int i = 0; i < n - 1; i++) {
        for (long long int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Check for selection sort inefficiency
    check_selection_sort_invariant(n == 100 && *min_element(a, a + n) == 0 && *max_element(a, a + n) == 1000000);

    for (long long int i = 0; i < n; i++) {
        c += a[0] - a[i];
    }

    cout << c;
    free(a); // Ensure to free the allocated memory
    return 0;
}