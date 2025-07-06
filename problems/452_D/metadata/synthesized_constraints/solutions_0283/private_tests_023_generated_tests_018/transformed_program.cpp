#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks

void check_machine_availability(int n1, int n2, int n3) {
    // Check if the number of machines is not sufficient for the throughput
    if (n1 < n2 || n2 < n3) {
        cerr << "Warning: Performance bottleneck due to limited availability of drying or folding machines!" << endl;
        abort();
    }
}

void check_high_machine_utilization(int t1, int t2, int t3, int n1, int n2, int n3) {
    // Check if processing times are high relative to the number of machines
    if (t1 > t2 * n2 / n1 || t2 > t3 * n3 / n2 || t3 > 1000 / (n1 + n2 + n3)) {
        cerr << "Warning: Performance bottleneck due to high machine utilization!" << endl;
        abort();
    }
}

void check_sequential_dependency_imbalance(int t1, int t2, int t3, int n1, int n2, int n3) {
    // Check if sequential dependency causes a bottleneck due to imbalance
    if (t1 > t2 && n1 >= n2 || t2 > t3 && n2 >= n3) {
        cerr << "Warning: Performance bottleneck due to sequential dependency imbalance!" << endl;
        abort();
    }
}

int main() {
  int k, n[5], t[5], r[5][1005], ks, kt, rm, res;
  bool w[5][1005];
  
  cin >> k;
  ks = k;
  
  for (int i = 1; i <= 3; i++) cin >> n[i];
  for (int i = 1; i <= 3; i++) cin >> t[i];

  // Place checkers after input reading
  check_machine_availability(n[1], n[2], n[3]);
  check_high_machine_utilization(t[1], t[2], t[3], n[1], n[2], n[3]);
  check_sequential_dependency_imbalance(t[1], t[2], t[3], n[1], n[2], n[3]);

  while (kt < ks) {
    for (int i = 3; i >= 1; i--) {
      for (int j = 0; j < n[i]; j++) {
        if (r[i][j] == 0 && w[i][j]) {
          if (i == 3) {
            kt++;
            w[i][j] = false;
          } else {
            for (int k = 0; k < n[i + 1]; k++)
              if (!w[i + 1][k]) {
                w[i + 1][k] = true;
                r[i + 1][k] = t[i + 1];
                w[i][j] = false;
                break;
              }
          }
        }
      }
    }
    for (int i = 0; i < n[1]; i++) {
      if (!w[1][i] && k > 0) {
        w[1][i] = true;
        k--;
        r[1][i] = t[1];
      }
    }
    rm = 1005;
    for (int i = 1; i <= 3; i++)
      for (int j = 0; j < n[i]; j++)
        if (r[i][j] != 0) rm = min(rm, r[i][j]);
    for (int i = 1; i <= 3; i++)
      for (int j = 0; j < n[i]; j++)
        if (r[i][j] != 0) r[i][j] -= rm;
    res += rm;
  }
  cout << res - rm;
  return 0;
}