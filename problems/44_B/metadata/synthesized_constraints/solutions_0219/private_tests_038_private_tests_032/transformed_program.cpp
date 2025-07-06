#include <bits/stdc++.h>
using namespace std;

// Invariant checks
void check_large_bottles_invariant(int N, int b, int c) {
    if (c > 4000 && b > 4000 && N > 8000) {
        cerr << "Warning: Large bottles invariant triggered - potential nested loop slowdown due to high values of b and c" << endl;
        abort();
    }
}

void check_total_bottles_invariant(int N, int a, int b, int c) {
    if ((a + b + c) > (N + 5000)) {
        cerr << "Warning: Total bottles invariant triggered - excessive bottle combinations considered" << endl;
        abort();
    }
}

void check_high_N_invariant(int N, int a, int b, int c) {
    if (N > 9500 && (a + b + c) > 8000) {
        cerr << "Warning: High N invariant triggered - high computational cost due to large N" << endl;
        abort();
    }
}

int main() {
    int N, a, b, c;
    scanf("%d %d %d %d", &N, &a, &b, &c);

    // Run the performance checks
    check_large_bottles_invariant(N, b, c);
    check_total_bottles_invariant(N, a, b, c);
    check_high_N_invariant(N, a, b, c);

    int ways = 0;
    for (int cc = 0; cc <= min(N / 2, c); cc++) {
        if (cc * 2 > N) break;
        for (int bb = 0; bb <= min(N - cc * 2, b); bb++) {
            if (cc * 2 + bb > N) break;
            if ((N - cc * 2 - bb) * 2 <= a) ways++;
        }
    }
    printf("%d", ways);
    return 0;
}