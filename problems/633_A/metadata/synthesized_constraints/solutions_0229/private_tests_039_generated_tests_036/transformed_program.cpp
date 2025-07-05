#include <iostream>
#include <algorithm>
using namespace std;

// Check if a and b are equal or share a high common factor
void check_high_common_factor_invariant(int a, int b, int c) {
    if (a == b || __gcd(a, b) > min(a, b) / 2) {
        cerr << "Warning: High common factor may cause performance issues!" << endl;
        abort();
    }
}

// Check if target c is a linear combination of a and b with small coefficients
void check_non_matching_damage_target_invariant(int a, int b, int c) {
    if (c % a != 0 && c % b != 0 && c > a * 10 && c > b * 10) {
        cerr << "Warning: Non-matching damage target with small coefficients!" << endl;
        abort();
    }
}

// Check if the target c is large compared to a and b
void check_large_target_with_small_damage_range_invariant(int a, int b, int c) {
    if (c > a * 50 && c > b * 50) {
        cerr << "Warning: Large target compared to small damage range!" << endl;
        abort();
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Check for performance bottleneck conditions
    check_high_common_factor_invariant(a, b, c);
    check_non_matching_damage_target_invariant(a, b, c);
    check_large_target_with_small_damage_range_invariant(a, b, c);

    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j <= 10000; j++) {
            if ((i * a) + (j * b) == c) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}