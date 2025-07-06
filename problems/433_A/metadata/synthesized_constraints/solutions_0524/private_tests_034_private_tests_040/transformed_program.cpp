#include <bits/stdc++.h>
using namespace std;

void check_large_iteration_invariant(int n) {
    // Approximately check if the combination leads to excessive iterations
    if (n >= 100) {
        cerr << "Warning: Performance bottleneck condition triggered due to large iteration count!" << endl;
        abort();
    }
}

void check_imbalanced_weights_invariant(int s1, int s2) {
    // Check for highly imbalanced distribution
    if (s1 == 0 || s2 == 0) {
        cerr << "Warning: Performance bottleneck condition triggered due to imbalanced weight distribution!" << endl;
        abort();
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == 100)
      s1++;
    else
      s2++;
  }

  // Insert checks after computing s1 and s2
  check_large_iteration_invariant(n);
  check_imbalanced_weights_invariant(s1, s2);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int m = 0; m < n; m++) {
          if (i + j + k + m == n && i + k == s1 && j + m == s2) {
            int a = j - m;
            int b = k - i;
            if (200 * a == 100 * b) {
              cout << "YES" << '\n';
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "NO" << '\n';
  return 0;
}