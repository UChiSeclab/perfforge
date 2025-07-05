#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];

// Invariant #1: Nested Loop Traversal
void check_nested_loop_invariant(int n, int operations) {
    if (operations > n * n) { // Arbitrarily assuming a threshold related to n^2
        cerr << "Warning: Performance bottleneck due to excessive nested loop operations!" << endl;
        abort();
    }
}

// Invariant #2: Complexity Due to Sorted Array Exploration
void check_sorted_array_exploration(bool condition) {
    if (condition) {
        cerr << "Warning: Excessive search operations in sorted array!" << endl;
        abort();
    }
}

// Invariant #3: Input Pattern and Weight Distribution
void check_distribution_invariant(int count100, int count200, int n) {
    if (abs(count100 - count200) > n / 2) { // Arbitrary threshold based on n
        cerr << "Warning: Imbalanced distribution of apple weights!" << endl;
        abort();
    }
}

int main() {
    int n;
    string s;
    while (cin >> n) {
        int flag = false;
        int sum = 0;
        int count100 = 0, count200 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 100) count100++;
            else count200++;
        }
        
        // Check input distribution
        check_distribution_invariant(count100, count200, n);

        int y = sum / 2;
        int sum2;
        sort(a, a + n);
        
        int operations = 0; // Track operations for nested loop invariant
        for (int i = 0; i < n - 1; i++) {
            sum2 = 0;
            for (int j = i; j < n; j++) {
                sum2 += a[j];
                operations++;
                if (sum2 < y) continue;
                if (sum2 == y) {
                    flag = true;
                    break;
                }
                if (sum2 > y) break;
            }
            if (flag) break;
        }
        
        // Check nested loop operations
        check_nested_loop_invariant(n, operations);
        
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}