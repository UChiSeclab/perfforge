#include <bits/stdc++.h>
using namespace std;

int n, k, a[200004], m, i;

// Check for large cluster near the initial median
void check_cluster_invariant(int m, int n, int a[]) {
    int threshold = 1000;  // Arbitrary threshold for demonstration
    int cluster_count = 0;
    for (int j = m; j < n; ++j) {
        if (a[j] == a[m]) cluster_count++;
        else break;
    }
    if (cluster_count > threshold) {
        cerr << "Warning: Cluster near median too large, performance bottleneck!" << endl;
        abort();
    }
}

// Check excessive while-loop execution
void check_while_loop_invariant(int while_hits, int limit) {
    if (while_hits > limit) {
        cerr << "Warning: Excessive while-loop iterations, performance bottleneck!" << endl;
        abort();
    }
}

int main() {
  cin >> n >> k;
  m = n / 2;
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  // Integrating the cluster invariant check after sorting
  check_cluster_invariant(m, n, a);

  int while_hits = 0;  // Counter for while-loop iterations
  for (i = a[m]; k > 0; i++) {
    while (i == a[m + 1]) {
      m++;
      while_hits++;
    }
    k -= m - n / 2 + 1;
  }

  // Integrating the while-loop invariant check
  check_while_loop_invariant(while_hits, 1000000);  // Threshold for demonstration

  if (k == 0)
    cout << i << endl;
  else
    cout << i - 1 << endl;
}