#include <bits/stdc++.h>
using namespace std;
int arr[3];

// Function to check iteration invariant
void check_iteration_invariant(int arr[]) {
    int lcm12 = std::lcm(arr[0], arr[1]);
    int lcm123 = std::lcm(lcm12, arr[2]);
    if (lcm123 > 1000) {
        cerr << "Warning: Iteration invariant triggered - excessive common multiples." << endl;
        abort();
    }
}

// Function to check reset invariant
void check_reset_invariant(int resetCount) {
    if (resetCount > 100) {
        cerr << "Warning: Reset invariant triggered - excessive frequency array resets." << endl;
        abort();
    }
}

// Function to check excessive loops invariant
void check_excessive_loops_invariant(int loopIterations) {
    if (loopIterations >= 1000) {
        cerr << "Warning: Excessive loops invariant triggered - maximum iterations reached." << endl;
        abort();
    }
}

bool check() {
    bool freq[1005];
    memset(freq, 0, sizeof(freq));
    int resetCount = 0;  // Count the number of times freq array is reset
    int loopIterations = 0;  // Count total loop iterations

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                loopIterations++;
                for (int m = i; m <= 1000; m += arr[0]) freq[m] = 1;
                for (int m = j; m <= 1000; m += arr[1]) freq[m] = 1;
                for (int m = k; m <= 1000; m += arr[2]) freq[m] = 1;
                bool good = true;
                for (int m = max(i, max(j, k)); m <= 1000; m++) good &= freq[m];
                if (good) return true;
                for (int m = 1; m <= 1000; m++) freq[m] = false;
                resetCount++;
            }
        }
    }

    // Check reset invariant and loop invariant after the main loop
    check_reset_invariant(resetCount);
    check_excessive_loops_invariant(loopIterations);

    return false;
}

int main() {
    cin >> arr[0] >> arr[1] >> arr[2];
    // Sort intervals to optimize the loop structure
    sort(arr, arr + 3);

    // Check the iteration invariant after sorting
    check_iteration_invariant(arr);

    if (check()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}