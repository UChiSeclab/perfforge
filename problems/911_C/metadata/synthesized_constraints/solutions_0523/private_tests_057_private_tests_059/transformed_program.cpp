#include <bits/stdc++.h>
using namespace std;

long long a, b, c, pa = -1, pb = -1, pc = -1;

void check_equal_intervals_invariant(long long a, long long b) {
    if (a == b) {
        cerr << "Warning: Performance bottleneck condition triggered - equal interval values." << endl;
        abort();
    }
}

void check_any_equal_intervals_invariant(long long a, long long b, long long c) {
    if (a == b || b == c || a == c) {
        cerr << "Warning: Performance bottleneck condition triggered - at least two equal intervals." << endl;
        abort();
    }
}

void check_slow_path_conditions(long long a, long long b, long long c) {
    if ((a % b == 0) || (b % c == 0) || (a % c == 0)) {
        cerr << "Warning: Slow path condition triggered - overlapping interval values causing slow execution." << endl;
        abort();
    }
}

int main() {
    scanf("%lld%lld%lld", &a, &b, &c);

    // Perform checks to detect potential performance bottlenecks
    check_equal_intervals_invariant(a, b);
    check_any_equal_intervals_invariant(a, b, c);
    check_slow_path_conditions(a, b, c);

    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    for (int i = 1; i <= 10000000; i++) {
        if (pa == -1) {
            pa = i % a;
            continue;
        }
        if (i % a != pa) {
            if (pb == -1) {
                pb = i % b;
                continue;
            }
            if (i % b != pb) {
                if (pc == -1) {
                    pc = i % c;
                    continue;
                }
                if (i % c != pc) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
}