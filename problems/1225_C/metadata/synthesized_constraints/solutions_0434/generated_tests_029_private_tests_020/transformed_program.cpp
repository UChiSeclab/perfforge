#include <bits/stdc++.h>
using namespace std;

// Function to check if the loop is taking too many iterations
void check_loop_invariant(int N, int P, int i) {
    if (P > 0 && (N - P * i > 0)) {
        cerr << "Warning: Performance bottleneck due to excessive loop iterations triggered!" << endl;
        abort();
    }
}

// Function to check if binary digit counting is excessive
void check_binary_count_invariant(int iterations) {
    if (iterations > 1000000) {
        cerr << "Warning: Performance bottleneck due to excessive binary counting triggered!" << endl;
        abort();
    }
}

// Function to check if condition checks are causing performance issues
void check_condition_invariant(int cnt, int i, int t) {
    if (cnt > i && i <= t) {
        cerr << "Warning: Performance bottleneck due to unsatisfied condition triggered!" << endl;
        abort();
    }
}

int main() {
    int N, P;
    scanf("%d%d", &N, &P);
    for (int i = 0; i <= 1000100; i++) {
        int t = N - P * i;

        // Check loop invariant before intensive computation
        check_loop_invariant(N, P, i);

        int cnt = 0;
        int iterations = 0; // Track iterations within the while loop

        while (t) {
            cnt += t % 2;
            t /= 2;
            iterations++;
        }

        // Check binary count invariant after the while loop
        check_binary_count_invariant(iterations);

        if (cnt <= i && i <= N - P * i) {
            printf("%d\n", i);
            return 0;
        }

        // Check condition invariant after evaluating the condition
        check_condition_invariant(cnt, i, N - P * i);
    }
    printf("-1\n");
}