#include <bits/stdc++.h>
using namespace std;

// Checker function for large combination space
void check_apple_combination_invariant(int sum1, int sum2) {
    if ((sum1 + sum2) > 50) {  // This threshold is arbitrary, based on the combination space being large
        cerr << "Warning: Performance bottleneck condition triggered due to large combination space!" << endl;
        abort();
    }
}

// Checker function for complex distribution pattern
void check_balanced_distribution_invariant(int sum1, int sum2, int totalWeight) {
    if ((totalWeight % 2 == 0) && (sum1 > 0 && sum2 > 0) && abs(sum1 - sum2) < 10) {  // Threshold for arbitrary complexity
        cerr << "Warning: Performance bottleneck condition triggered due to complex distribution pattern!" << endl;
        abort();
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0, sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            sum += k;
            if (k == 100) {
                sum1++;
            } else {
                sum2++;
            }
        }
        
        // Insert checker for large combination space
        check_apple_combination_invariant(sum1, sum2);

        if (n == 1) {
            puts("NO");
            continue;
        }
        if (sum % 2 != 0) {
            puts("NO");
            continue;
        }
        
        int k = sum / 2;
        int flag = 0;
        
        // Insert checker for complex distribution pattern
        check_balanced_distribution_invariant(sum1, sum2, sum);
        
        for (int i = 0; i <= sum1; i++) {
            for (int j = 0; j <= sum2; j++) {
                if (i * 100 + j * 200 == k) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        
        if (flag) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}