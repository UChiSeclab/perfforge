#include <bits/stdc++.h>
using namespace std;

// Checker for Invariant #1
void check_large_200_gram_apples(int n, int count_200) {
    if (n == 100 && count_200 > 70) {
        cerr << "Warning: Performance bottleneck condition triggered - too many 200-gram apples" << endl;
        abort();
    }
}

// Checker for Invariant #2
void check_frequent_updates(int potential_updates) {
    if (potential_updates > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered - too many updates to 'can' array" << endl;
        abort();
    }
}

// Checker for Invariant #3
void check_difficult_partitioning(int sum) {
    if (sum > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - difficult weight partitioning" << endl;
        abort();
    }
}

int a[400];
int can[1000];

int main() {
    int n;
    scanf("%d", &n);
    int s = 0;
    can[0] = 1;

    int count_200 = 0; // Count the number of 200-gram apples
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        k /= 100;
        if (k == 2) count_200++; // Increment count for 200-gram apples

        s += k;

        int potential_updates = 0; // Track potential updates to 'can'
        for (int t = 1000 - 1; t >= 0; t--) {
            if (can[t]) {
                can[t + k] = 1;
                potential_updates++;
            }
        }
        check_frequent_updates(potential_updates); // Check for excessive updates
    }

    check_large_200_gram_apples(n, count_200); // Check for too many 200-gram apples
    check_difficult_partitioning(s); // Check for difficult partitioning
    
    if (s % 2)
        puts("NO");
    else {
        int p = s / 2;
        if (can[p])
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}