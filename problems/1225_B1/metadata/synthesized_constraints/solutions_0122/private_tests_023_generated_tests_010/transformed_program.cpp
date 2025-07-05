#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_variety_in_short_segments(int distinctShowCount, int d) {
    if (distinctShowCount > d) {
        cerr << "Warning: High variety of shows in a short segment detected!" << endl;
        abort();
    }
}

void check_small_d_relative_to_n(int n, int d) {
    if (d < n / 10) {
        cerr << "Warning: Small 'd' relative to 'n' detected, causing inefficient segment processing!" << endl;
        abort();
    }
}

void check_frequent_non_zero_entries(int nonZeroCount, int threshold) {
    if (nonZeroCount > threshold) {
        cerr << "Warning: Frequent non-zero entries in 'temp' detected, indicating high variety!" << endl;
        abort();
    }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, d;
    cin >> n >> k >> d;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    // Check if 'd' is considerably smaller than 'n'
    check_small_d_relative_to_n(n, d);
    
    int temp[101] = {0};
    int max_day = INT_MAX, count = 0;
    for (int i = 0; i + d <= n; i++) {
      for (int j = i; j < d + i; j++) {
        temp[arr[j]]++;
      }
      
      int nonZeroCount = 0;
      for (int k = 0; k <= 100; k++) {
        if (temp[k] != 0) {
          count++;
          nonZeroCount++;
          temp[k] = 0;
        }
      }
      
      // Check for high variety in short segments
      check_high_variety_in_short_segments(count, d);

      // Check for frequent non-zero entries
      check_frequent_non_zero_entries(nonZeroCount, 20); // Assume 20 is a threshold for high variety

      max_day = min(max_day, count);
      count = 0;
    }
    cout << max_day << endl;
  }
  return 0;
}