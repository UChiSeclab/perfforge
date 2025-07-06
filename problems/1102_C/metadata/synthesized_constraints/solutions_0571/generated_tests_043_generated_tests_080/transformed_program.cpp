#include <bits/stdc++.h>
using namespace std;

// Checker function for excessive swaps
void check_sort_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: sort_invariant triggered - excessive swaps due to unordered input" << endl;
        abort();
    }
}

// Checker function for many low durability doors
void check_low_durability_invariant(int count, int n) {
    if (count > n / 2) {
        cerr << "Warning: low_durability_invariant triggered - many doors have low durability" << endl;
        abort();
    }
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (x > y) {
        cout << n;
        return 0;
    }
    
    // Count low durability doors
    int lowDurabilityCount = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= x) {
            lowDurabilityCount++;
        }
    }

    // Check for performance bottleneck due to low durability
    check_low_durability_invariant(lowDurabilityCount, n);

    // Bubble sort
    int swapCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapCount++;
            }
        }
    }

    // Check for performance bottleneck due to sorting
    check_sort_invariant(swapCount > n * (n - 1) / 4); // Some threshold for excessive swaps

    int num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) break;
        num++;
    }

    if (num % 2 == 1) {
        cout << num / 2 + 1;
    }
    if (num % 2 == 0) {
        cout << num / 2;
    }
    
    return 0;
}