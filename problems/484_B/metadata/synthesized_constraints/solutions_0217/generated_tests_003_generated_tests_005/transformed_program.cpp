#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000 + 10;
int Q[MAX_N];
int N;

// Check for small divisors relative to the maximum element
void check_small_divisor_invariant(int x, int maxElement) {
    if (x < maxElement / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - small divisor relative to max element!" << endl;
        abort();
    }
}

// Check for dense sequence
void check_dense_sequence_invariant(const int* Q, int N, int threshold) {
    for (int i = 1; i < N; ++i) {
        if (Q[i] - Q[i - 1] < threshold) {
            cerr << "Warning: Performance bottleneck condition triggered - dense sequence!" << endl;
            abort();
        }
    }
}

// Check for repeated similar values
void check_repeated_values_invariant(const int* Q, int N) {
    unordered_map<int, int> frequency;
    for (int i = 0; i < N; ++i) {
        frequency[Q[i]]++;
        if (frequency[Q[i]] > N / 10) {
            cerr << "Warning: Performance bottleneck condition triggered - repeated similar values!" << endl;
            abort();
        }
    }
}

int judge(int x) {
    int p = x, res = 0;
    while (p < 1000000 + 10) {
        p += x;
        int k = lower_bound(Q, Q + N, p) - Q;
        if (k == 0)
            continue;
        else
            k--;
        if (Q[k] <= x) continue;
        res = max(res, Q[k] % x);
    }
    return res;
}

int main() {
    scanf("%d", &N);
    int ans = 0;
    for (int i = 0; i < N; i++) scanf("%d", Q + i);
    
    sort(Q, Q + N);
    
    // Insert checks after sorting
    int maxElement = Q[N - 1];
    check_dense_sequence_invariant(Q, N, maxElement / 20); // Arbitrary threshold for density
    check_repeated_values_invariant(Q, N);

    for (int i = N - 1; i >= 0; i--) {
        check_small_divisor_invariant(Q[i], maxElement); // Check for small divisors
        if (ans > Q[i] - 1) break;
        if (i < N - 1 && Q[i] == Q[i - 1]) continue;
        ans = max(ans, judge(Q[i]));
    }

    printf("%d\n", ans);
    return 0;
}