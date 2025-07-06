#include <bits/stdc++.h>
using namespace std;

int arr[3];

// Checker functions for performance invariants
void check_nested_loop_invariant(int i, int j, int k) {
    if (i > 90 || j > 90 || k > 90) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive nested loop iterations!" << endl;
        abort();
    }
}

void check_frequency_update_invariant(int k1, int k2, int k3) {
    if (k1 + k2 + k3 > 3000) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient frequency array updates!" << endl;
        abort();
    }
}

void check_array_reset_invariant(int iterations) {
    if (iterations > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive array reset operations!" << endl;
        abort();
    }
}

bool check() {
    bool freq[1005];
    memset(freq, 0, sizeof(freq));
    int iteration_count = 0;

    check_frequency_update_invariant(arr[0], arr[1], arr[2]);

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                check_nested_loop_invariant(i, j, k);

                for (int m = i; m <= 1000; m += arr[0]) freq[m] = 1;
                for (int m = j; m <= 1000; m += arr[1]) freq[m] = 1;
                for (int m = k; m <= 1000; m += arr[2]) freq[m] = 1;
                bool good = true;
                for (int m = max(i, max(j, k)); m <= 1000; m++) good &= freq[m];
                if (good) return true;
                for (int m = 1; m <= 1000; m++) freq[m] = false;

                iteration_count++;
                check_array_reset_invariant(iteration_count);
            }
        }
    }

    return false;
}

int main() {
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if (check()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}