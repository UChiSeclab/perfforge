#include <bits/stdc++.h>
using namespace std;

// Function declarations for invariants
void check_high_frequency_of_impossible_combinations(int n) {
    if (n <= 6 && n != 3 && n != 6) {
        cerr << "Warning: High frequency of impossible combinations detected!" << endl;
        abort();
    }
}

void check_large_number_of_small_test_cases(int m, int n) {
    if (m > 20 && n <= 6 && n != 3 && n != 6) {
        cerr << "Warning: Large number of small test cases detected!" << endl;
        abort();
    }
}

void check_exhaustive_check_for_small_n(int n) {
    if (n <= 6 && n != 3 && n != 6) {
        cerr << "Warning: Exhaustive check for small `n` detected!" << endl;
        abort();
    }
}

int main() {
    long long i, j, k, l, m, n;
    cin >> m;

    while (m--) {
        k = 0;
        cin >> n;

        // Check invariants
        check_high_frequency_of_impossible_combinations(n);
        check_large_number_of_small_test_cases(m, n);
        check_exhaustive_check_for_small_n(n);

        for (i = 0; i < 100; i++) {
            for (j = 0; j < 100; j++) {
                if ((3 * i + j * 7) == n) k++;
            }
        }
        if (k > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}