#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 4;
int a[maxn], b[maxn];

// Checkers for performance-characterizing invariants
void check_high_frequency_invariant(int frequency, int n) {
    if (frequency > n / 2) { // Arbitrary threshold where frequency is high
        cerr << "Warning: High frequency of a single coin value!" << endl;
        abort();
    }
}

void check_large_n_with_duplicates(int n, int uniqueCount) {
    if (n > 50 && uniqueCount < n / 2) { // n is large and few unique values
        cerr << "Warning: Large n with many duplicates!" << endl;
        abort();
    }
}

void check_on2_operations(int n) {
    if (n == 100) { // n is at its upper limit
        cerr << "Warning: O(n^2) operations likely!" << endl;
        abort();
    }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  // Check for potential O(n^2) operations due to maximum input size
  check_on2_operations(n);

  map<int, int> freq;

  for (int i = 1; i <= n; i++) {
      freq[a[i]]++;
  }

  // Determine the maximum frequency of any single value
  int maxFrequency = 0;
  for (auto& pair : freq) {
      maxFrequency = max(maxFrequency, pair.second);
  }

  // Check for high frequency of a single coin value
  check_high_frequency_invariant(maxFrequency, n);

  // Check for large n with many duplicates
  check_large_n_with_duplicates(n, freq.size());

  // Original logic
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i] == a[j]) b[i]++;
    }

  sort(b + 1, b + n + 1);
  cout << b[n];
  return 0;
}