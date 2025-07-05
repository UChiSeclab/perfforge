#include <bits/stdc++.h>
using namespace std;

void check_similar_damage_invariant(int a, int b) {
    if (abs(a - b) <= 1) { // Assuming 'close' means a difference of 1 unit
        cerr << "Warning: Performance bottleneck condition triggered - similar damage values may cause extensive search space exploration!" << endl;
        abort();
    }
}

void check_unreachable_damage_invariant(int a, int b, int c) {
    bool is_unreachable = true;
    for (int i = 0; i <= c/a; ++i) {
        if ((c - i * a) % b == 0) {
            is_unreachable = false;
            break;
        }
    }
    if (is_unreachable) {
        cerr << "Warning: Performance bottleneck condition triggered - unreachable damage value causing excessive iterations!" << endl;
        abort();
    }
}

void check_low_difference_invariant(int a, int b) {
    if (abs(a - b) <= 2) { // Arbitrary small threshold for 'minimal' difference
        cerr << "Warning: Performance bottleneck condition triggered - low difference between damage units!" << endl;
        abort();
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    // Insert invariant checks after reading inputs
    check_similar_damage_invariant(n, m);
    check_unreachable_damage_invariant(n, m, k);
    check_low_difference_invariant(n, m);

    for (int i = 0; i <= 10000; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            if (n * i + m * j == k) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}