#include <bits/stdc++.h>
using namespace std;

int arr[3];

// Function to check nested loop iterations
void check_loop_invariant(int i, int j, int k) {
    if (i > 40 && j > 40 && k > 40) { 
        cerr << "Warning: Performance bottleneck due to excessive loop iterations!" << endl;
        abort();
    }
}

// Function to check frequency updates
void check_frequency_invariant(int m, int arrSize) {
    if (m > 900 && arrSize > 3) {
        cerr << "Warning: Performance bottleneck due to excessive frequency updates!" << endl;
        abort();
    }
}

// Function to check array access
void check_array_access_invariant(int accessCount) {
    if (accessCount > 500000) {
        cerr << "Warning: Performance bottleneck due to excessive array access!" << endl;
        abort();
    }
}

bool check() {
  bool freq[1005];
  memset(freq, 0, sizeof(freq));
  int accessCount = 0; // Count accesses to the frequency array
  for (int i = 1; i <= 50; i++) {
    for (int j = 1; j <= 50; j++) {
      for (int k = 1; k <= 50; k++) {
        check_loop_invariant(i, j, k); // Check for excessive loop iterations
        for (int m = i; m <= 1000; m += arr[0]) {
            freq[m] = 1;
            accessCount++;
        }
        for (int m = j; m <= 1000; m += arr[1]) {
            freq[m] = 1;
            accessCount++;
        }
        for (int m = k; m <= 1000; m += arr[2]) {
            freq[m] = 1;
            accessCount++;
        }
        bool good = true;
        for (int m = max(i, max(j, k)); m <= 1000; m++) {
            good &= freq[m];
            check_frequency_invariant(m, 3); // Check excessive frequency updates
        }
        if (good) return true;
        for (int m = 1; m <= 1000; m++) {
            freq[m] = false;
            accessCount++;
        }
      }
    }
  }
  check_array_access_invariant(accessCount); // Check for excessive array access
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