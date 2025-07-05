#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_large_number_construction(int len) {
    if (len > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large number construction!" << endl;
        abort();
    }
}

void check_frequent_conditional_checks(int len, int max_iter) {
    if (len * max_iter > 2000) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent conditional checks!" << endl;
        abort();
    }
}

void check_string_operations_in_loops(int len) {
    if (len > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive string operations!" << endl;
        abort();
    }
}

void check_high_loop_iterations(int len) {
    if (len > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - high loop iterations!" << endl;
        abort();
    }
}

int main() {
    int k;
    cin >> k;
    int n = 9;
    int a[10];
    int minm = INT_MAX, ind = -1;
    for (int i = 1; i <= 9; i++) {
        int x;
        cin >> x;
        a[i] = x;
        if (minm > a[i]) {
            minm = a[i];
            ind = i;
        }
    }
    int len = k / minm;
    check_large_number_construction(len); // Check for large number construction
    check_high_loop_iterations(len);      // Check for high loop iterations

    if (len == 0) {
        cout << "-1\n";
    } else {
        string ans = "";
        k = k - (len)*minm;
        for (int i = 0; i < len; i++) {
            ans += to_string(ind);
            check_string_operations_in_loops(len); // Check for extensive string operations
        }
        int i = 9, j = 0;
        int max_iter = 0;
        while (j < ans.length() && i > 0) {
            max_iter++;
            if (k + a[ans[j] - '0'] >= a[i]) {
                string f = to_string(i);
                k = k + a[ans[j] - '0'] - a[i];
                ans[j] = f[0];
                j++;
            } else
                i--;
        }
        check_frequent_conditional_checks(len, max_iter); // Check for frequent conditional checks
        cout << ans << "\n";
    }
}