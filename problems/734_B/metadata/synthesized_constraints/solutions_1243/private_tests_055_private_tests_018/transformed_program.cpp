#include <bits/stdc++.h>
using namespace std;

void check_large_digit_counts(long long a2, long long a5, long long a6) {
    if (min({a2, a5, a6}) > 4e6) { // Example threshold; can be adjusted
        cerr << "Warning: Performance bottleneck condition triggered due to large counts of 2, 5, and 6!" << endl;
        abort();
    }
}

void check_fast_path(long long a2) {
    if (a2 == 0) {
        cerr << "Info: Fast execution path due to absence of digit 2!" << endl;
        // No abort here since this is an informational check
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    long long a2, a3, a5, a6;
    cin >> a2 >> a3 >> a5 >> a6;

    // Perform checks based on performance-characterizing invariants
    check_large_digit_counts(a2, a5, a6);
    check_fast_path(a2);
    
    long long sum = 0;
    while (1) {
        if (a2 >= 1 && a5 >= 1 && a6 >= 1) {
            sum += 256;
            a2--, a5--, a6--;
        } else if (a2 >= 1 && a3 >= 1) {
            sum += 32;
            a2--, a3--;
        } else
            break;
    }
    cout << sum << endl;
    return 0;
}