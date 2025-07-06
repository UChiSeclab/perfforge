#include <bits/stdc++.h>
using namespace std;

// Function to check for midpoint clustering
void check_midpoint_clustering(int* a, int n) {
    int mid_point = 500000;
    int left_closer = 0, right_closer = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= mid_point) left_closer++;
        if (a[i] >= mid_point) right_closer++;
    }
    if (left_closer > 0 && right_closer > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - midpoint clustering!" << endl;
        abort();
    }
}

// Function to check for balanced distribution
void check_balanced_distribution(int* a, int n) {
    int quarter1 = 250000;
    int quarter3 = 750000;
    int count1 = 0, count3 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < quarter1) count1++;
        if (a[i] > quarter3) count3++;
    }
    if (count1 > 0 && count3 > 0 && (count1 + count3 < n)) {
        cerr << "Warning: Performance bottleneck condition triggered - balanced distribution!" << endl;
        abort();
    }
}

// Function to check for large gaps between prizes
void check_large_gap(int* a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] > 100000) { // Arbitrary threshold for a "large" gap
            cerr << "Warning: Performance bottleneck condition triggered - large gap between prizes!" << endl;
            abort();
        }
    }
}

int main() {
    int n, c = 0, s1 = 0, s = 0, l = 0, m, sec;
    cin >> n;
    m = n - 1;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Insert performance checks after reading input
    check_midpoint_clustering(a, n);
    check_balanced_distribution(a, n);
    check_large_gap(a, n);
    
    for (int i = 2, k = 999999; c != n; i++, k--) {
        if (i == a[l]) {
            s1 = i - 2 + 1;
            c++;
            l++;
        }
        if (k == a[m]) {
            s = 1000000 - k;
            c++;
            m--;
        }
    }
    if (s > s1)
        sec = s;
    else
        sec = s1;
    cout << sec;
}