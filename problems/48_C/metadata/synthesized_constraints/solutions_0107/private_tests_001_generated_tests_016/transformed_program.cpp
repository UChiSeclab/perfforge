#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1010;
const double Inf = 100010;

// Invariant checker functions
void check_loop_range_invariant(int iterationCount, int threshold) {
    if (iterationCount > threshold) {
        cerr << "Warning: Loop range invariant triggered - excessive iterations in outer loop!" << endl;
        abort();
    }
}

void check_inner_loop_invariant(int N, int threshold) {
    if (N > threshold) {
        cerr << "Warning: Inner loop invariant triggered - large number of stations leading to frequent execution!" << endl;
        abort();
    }
}

void check_condition_fail_invariant(int failCount, int threshold) {
    if (failCount > threshold) {
        cerr << "Warning: Condition fail invariant triggered - frequent invalid v values!" << endl;
        abort();
    }
}

void check_m_update_invariant(double mIncrement, double threshold) {
    if (mIncrement < threshold) {
        cerr << "Warning: m update invariant triggered - very small increments leading to excessive updates!" << endl;
        abort();
    }
}

int main() {
    int N;
    int a[MaxN];
    int i, j, t;
    int ans, tmp;
    double m, v;
    bool ill, uni;
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &a[i + 1]);
    a[0] = 0;
    ans = -1;
    uni = 0;
    m = a[1] * 10;

    // Check the inner loop invariant
    check_inner_loop_invariant(N, 500);  // Example threshold

    int iterationCount = 0;
    int conditionFailCount = 0;
    double mIncrement = 0.00001;  // As used in the loop

    // Check the m update invariant
    check_m_update_invariant(mIncrement, 0.0001);  // Example threshold

    for (t = 0; t < 1000000; t++) {
        iterationCount++;
        v = m;
        ill = 0;
        for (i = 1; i <= N; i++) {
            v -= (double)(a[i] - a[i - 1]) * 10;
            if (v < 0 || v > 10) {
                ill = 1;
                conditionFailCount++;
                break;
            }
            v += m;
        }
        m += mIncrement;
        if (ill) continue;
        tmp = a[N] + (int)(v / 10);
        if (ans == -1)
            ans = tmp;
        else if (ans != tmp) {
            uni = 1;
            break;
        }
    }

    // Check the loop range invariant
    check_loop_range_invariant(iterationCount, 500000);  // Example threshold

    // Check the condition fail invariant
    check_condition_fail_invariant(conditionFailCount, 300000);  // Example threshold

    if (uni)
        printf("not unique");
    else
        printf("unique\n%d", ans);
    return 0;
}