#include <bits/stdc++.h>
using namespace std;

int N, s1, s2, ans;
int a[2005], dc[2005];

void check_high_iteration_invariant(int n, std::vector<int>& frequencies) {
    int highFrequencyCount = 0;
    for (int freq : frequencies) {
        if (freq > 0) {
            highFrequencyCount++;
        }
    }
    if (highFrequencyCount > n / 2) {
        cerr << "Warning: High iteration count invariant triggered - too many elements with the same absolute value." << endl;
        abort();
    }
}

void check_density_of_repeated_elements(int n, std::map<int, int>& elementCounts) {
    for (auto& pair : elementCounts) {
        if (pair.second > n / 4) {
            cerr << "Warning: Density of repeated elements invariant triggered - high number of identical absolute values." << endl;
            abort();
        }
    }
}

void check_nested_loop_invariant(int n) {
    if (n > 1500) {
        cerr << "Warning: Nested loop overhead invariant triggered - large array size leading to excessive iterations." << endl;
        abort();
    }
}

void check_inversion_calculation_invariant(int n) {
    if (n > 1500) {
        cerr << "Warning: Inversion calculation complexity invariant triggered - potential high computation cost due to large n." << endl;
        abort();
    }
}

int main() {
    scanf("%d", &N);
    if (N > 2000) {
        cerr << "Warning: Input size exceeds limits!" << endl;
        abort();
    }
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++) a[i] = abs(a[i]);

    // Collect frequency information for invariants
    std::vector<int> frequencies(100001, 0);
    std::map<int, int> elementCounts;
    for (int i = 1; i <= N; i++) {
        frequencies[a[i]]++;
        elementCounts[a[i]]++;
    }

    // Insert checks for invariants
    check_high_iteration_invariant(N, frequencies);
    check_density_of_repeated_elements(N, elementCounts);
    check_nested_loop_invariant(N);
    check_inversion_calculation_invariant(N);

    memset(dc, 0, sizeof(dc));
    for (int i = 100000; i >= 0; i--) {
        for (int j = 1; j <= N; j++)
            if (a[j] == i) dc[j] = 2;
        for (int j = 1; j <= N; j++)
            if (a[j] == i) {
                s1 = 0;
                for (int k = 1; k < j; k++)
                    if (dc[k] == 1) {
                        if (a[k] > a[j]) ++s1;
                    }
                for (int k = j + 1; k <= N; k++)
                    if (dc[k] == 1) {
                        if (a[k] < a[j]) ++s1;
                    } else if (dc[k] != 2)
                        ++s1;
                s2 = 0;
                for (int k = 1; k < j; k++)
                    if (dc[k] == 1) {
                        if (a[k] > -a[j]) ++s2;
                    } else if (dc[k] != 2)
                        ++s2;
                for (int k = j + 1; k <= N; k++)
                    if (dc[k] == 1) {
                        if (a[k] < -a[j]) ++s2;
                    }
                if (s1 > s2) a[j] = -a[j];
            }
        for (int j = 1; j <= N; j++)
            if (a[j] == i) dc[j] = 1;
    }
    ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            if (a[i] > a[j]) ++ans;
    printf("%d\n", ans);
    return 0;
}