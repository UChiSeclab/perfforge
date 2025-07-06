#include <bits/stdc++.h>
using namespace std;

void check_loop_range_and_step_sizes(int a, int c, int b, int d) {
    if (a <= 5 && c <= 5 && abs(b - d) <= 10) {
        cerr << "Warning: Performance bottleneck due to small step sizes and close offsets!" << endl;
        abort();
    }
}

void check_common_divisor(int a, int c) {
    int gcd = std::__gcd(a, c);
    if (gcd > 1) {
        cerr << "Warning: Performance bottleneck due to common divisor of step sizes!" << endl;
        abort();
    }
}

void check_offset_alignment(int b, int d) {
    if ((b % 2 == d % 2) && ((b / 2) % 2 == (d / 2) % 2)) {
        cerr << "Warning: Performance bottleneck due to aligned offsets causing alternating screams!" << endl;
        abort();
    }
}

int a, b, c, d;

int main() {
    int i;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);

    // Inserted checks to detect performance bottlenecks
    check_loop_range_and_step_sizes(a, c, b, d);
    check_common_divisor(a, c);
    check_offset_alignment(b, d);

    int ret = -1;
    int mn = max(b, d);
    for (i = mn; i <= 100000000; i++) {
        int ok = 0;
        int val1 = i - b;
        if (val1 % a == 0) ok++;
        int val2 = i - d;
        if (val2 % c == 0) ok++;
        if (ok == 2) {
            ret = i;
            break;
        }
    }
    printf("%d", ret);
    printf("\n");
    return 0;
}